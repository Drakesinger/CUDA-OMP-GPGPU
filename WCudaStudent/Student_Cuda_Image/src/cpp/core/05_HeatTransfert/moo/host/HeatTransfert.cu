#include <iostream>
#include <assert.h>

#include "HeatTransfert.h"
#include "Device.h"

#include <math.h>
#include <limits>

#include "CalibreurF.h"


using std::cout;
using std::endl;
using std::string;

extern __global__ void heatEcrasement(float* ptrDevImage, float* ptrDevHeater, int w, int h);
extern __global__ void heatDiffusion(float* ptrDevIn, float* ptrDevOut, float k, int w, int h);
extern __global__ void heatImageHSB(float* ptrDevIn, uchar4* ptrDevOut, CalibreurF calibreur, int w, int h);

HeatTransfert::HeatTransfert(int w, int h, int iterations, float k):
	calibreur(IntervalF(0,1),IntervalF(0.7,0)),
	nbIteration(iterations),
	ptrTabHeater(new float[w * h]), ptrImgA(new float[w * h]), ptrImgB(new float[w * h])
    {
    // Inputs
    this->w = w;
    this->h = h;
    this->k = k;
    this->t = 0;

    std::fill(ptrTabHeater, ptrTabHeater + w * h, 0);
    std::fill(ptrImgB, ptrImgB + w * h, 0);


    // Tools
    this->dg = dim3(16, 8, 1);
    this->db = dim3(32, 2, 1);
    this->isPair = true;

    // Outputs
    this->title = "HeatTransfert";

    //print(dg, db);
    Device::assertDim(dg, db);

    //Remplissage des 4 zones bleu
    remplir(ptrTabHeater, 179, 179, 195, 195, 0.2,w,h);
    remplir(ptrTabHeater, 605, 179, 621, 195, 0.2,w,h);
    remplir(ptrTabHeater, 179, 605, 195, 621, 0.2,w,h);
    remplir(ptrTabHeater, 605, 605, 621, 621, 0.2,w,h);

    //Zone centrale
    remplir(ptrTabHeater, 300, 300, 500, 500, 1.0,w,h);

    //4 Pixel autour de la zone centrale
    remplir(ptrTabHeater, 400, 295, 401, 296, 0.2,w,h);
    remplir(ptrTabHeater, 295, 400, 296, 401, 0.2,w,h);
    remplir(ptrTabHeater, 400, 505, 401, 506, 0.2,w,h);
    remplir(ptrTabHeater, 505, 400, 506, 401, 0.2,w,h);

    size = w*h*sizeof(float);

    for (int i = 0; i < w * h; ++i)
    	ptrImgA[i] = ptrTabHeater[i];

    instanciateHeatDevImage(&ptrTabHeater, &ptrDevTabHeater, size);
    instanciateHeatDevImage(&ptrImgA, &ptrDevImgA, size);
    instanciateHeatDevImage(&ptrImgB, &ptrDevImgB, size);
    }

__host__ void HeatTransfert::instanciateHeatDevImage(float** ptr, float** ptrDev, size_t size)
    {
    HANDLE_ERROR(cudaMalloc((void** )ptrDev, size));
    HANDLE_ERROR(cudaMemcpy(*ptrDev, *ptr, size, cudaMemcpyHostToDevice));
    }

HeatTransfert::~HeatTransfert()
    {
    HANDLE_ERROR(cudaFree(&ptrDevTabHeater));
    HANDLE_ERROR(cudaFree(&ptrDevImgA));
    HANDLE_ERROR(cudaFree(&ptrDevImgB));

    delete[] ptrTabHeater;
    delete[] ptrDevImgB;
    delete[] ptrDevImgA;

    }

/*-------------------------*\
 |*     Methode override    *|
 \*-------------------------*/

void HeatTransfert::process(uchar4* ptrDevPixels, int w, int h)
    {

   /* if (this->isPair){
	startHeatDiffusion(ptrDevImgB, ptrDevImgA, k, w, h);
	startHeatEcrasement(ptrDevImgA, ptrTabHeater, w, h);
    }
    else{
	startHeatDiffusion(ptrDevImgA, ptrDevImgB, k, w, h);
	startHeatEcrasement(ptrDevImgB, ptrTabHeater, w, h);
    }

    this->isPair = !this->isPair;*/

    float *input, *output;

    input = isPair ? ptrDevImgA : ptrDevImgB;
    output = isPair ? ptrDevImgB : ptrDevImgA;

    startHeatDiffusion(input, output, k, w, h);
    startHeatEcrasement(output, ptrDevTabHeater, w, h);
    startHeatDiffusion(output, input, k, w, h);
    startHeatEcrasement(input, ptrDevTabHeater, w, h);

    startHeatImageHSB(output, ptrDevPixels, calibreur, w, h);

    //HANDLE_ERROR(cudaMemcpy(ptrDevPixels,ptrDevTabHeater,size,cudaMemcpyDeviceToDevice));
    //heatEcrasement<<<dg,db>>>(ptrDevPixels,ptrDevTabHeater, w, h);
    }

void HeatTransfert::initTab(float* ptrTab,int w,int h)
    {
    for(int i=0;i<(w*h);i++)
	{
	ptrTab[i] = 0.0;
	}
    }
__host__ void HeatTransfert::startHeatEcrasement(float* ptrDevImage, float* ptrDevHeater, int w, int h){
    heatEcrasement<<<this->dg, this->db>>>(ptrDevImage, ptrDevHeater, w, h);
    Device::checkKernelError("kernelEcrasement");
}

__host__ void HeatTransfert::startHeatDiffusion(float* ptrDevIn, float* ptrDevOut, float k, int w, int h)
    {
    heatDiffusion<<<this->dg, this->db>>>(ptrDevIn, ptrDevOut, k, w, h);
    Device::checkKernelError("kernelDiffusion");
    }


__host__ void HeatTransfert::startHeatImageHSB(float* ptrDevIn, uchar4* ptrDevOut, CalibreurF& calibreur, int w, int h)
    {
    heatImageHSB<<<this->dg,this->db>>>(ptrDevIn, ptrDevOut, calibreur, w, h);
    Device::checkKernelError("kernelHSB");
    }

void HeatTransfert::remplir(float* ptrTab, int x, int y, int x2, int y2, float value,int w,int h)
    {
    int offset = y*w+x;
    int hauteur = y2-y;
    int largeur = x2-x;
    int i=0;
    while(i<hauteur)
	{
	int j = 0;
	while(j < largeur)
	    {
	    ptrTab[offset+j] = value;
	    j+=1;
	    }
	i+=1;
	offset += w;
	}
    }

float HeatTransfert::getAnimationPara(void)
    {
    return this->t;
    }

void HeatTransfert::animationStep()
    {
    this->t += nbIteration;
    }

 /*--------------*\
 |* get override *|
 \*--------------*/
float HeatTransfert::getT(void)
    {
    return this->t;
    }

string HeatTransfert::getTitle(void)
    {
    return title;
    }
int HeatTransfert::getW(void)
    {
    return w;
    }
int HeatTransfert::getH(void)
    {
    return h;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
