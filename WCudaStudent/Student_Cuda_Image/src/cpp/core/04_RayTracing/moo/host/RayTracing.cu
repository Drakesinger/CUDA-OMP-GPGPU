#include <iostream>
#include <assert.h>

#include "DomaineMath.h"
#include "RayTracing.h"
#include "Device.h"

#include <math.h>
#include <limits>

#define BORD 200
#define LENGTH 500
__constant__ Sphere TAB_DATA_CM[LENGTH];

using std::cout;
using std::endl;
using std::string;

extern __global__ void rayTracing(uchar4* ptrDevPixels, int w, int h, Sphere* ptrDevSpheres, DomaineMath domaineMath, int length, float t);

extern Sphere* instanciateSpheres(Sphere*,int);
extern void destructSpheres(Sphere*);

RayTracing::RayTracing(int w, int h, DomaineMath* domaineMath, float dt)
    {
    // Inputs
    this->w = w;
    this->h = h;
    this->ptrDomaineMathInit = domaineMath;
    this->t = 0;
    this->dt = dt;

    // Tools
    this->dg = dim3(16, 8, 1);
    this->db = dim3(32, 2, 1);

    // Outputs
    this->title = "RayTracing";

    ptrSpheres = new Sphere[LENGTH];

    for(int i = 0; i < LENGTH; ++i)
	{
	float3 center;
	center.x = randomMinMax(BORD, w-BORD);
	center.y = randomMinMax(BORD, h-BORD);
	center.z = randomMinMax(10, 2*w);

	ptrSpheres[i] = *(new Sphere(center, randomMinMax(20,80), randomMinMax(0, 1)));
	}

    ptrDevSpheres = instanciateSpheres(ptrSpheres, LENGTH);
    }

RayTracing::~RayTracing()
    {
    destructSpheres(ptrDevSpheres);
    delete[] ptrSpheres;
    }

/*-------------------------*\
 |*     Methode override    *|
 \*-------------------------*/

void RayTracing::process(uchar4* ptrDevPixels, int w, int h, const DomaineMath& domaineMath)
    {
    rayTracing<<<dg,db>>>(ptrDevPixels, w, h, ptrDevSpheres, domaineMath,LENGTH ,t);
    }

float RayTracing::getAnimationPara(void)
    {
    return this->t;
    }

void RayTracing::animationStep()
    {
    this->t += dt;
    }

 /*--------------*\
 |* get override *|
 \*--------------*/
DomaineMath* RayTracing::getDomaineMathInit(void)
    {
    return ptrDomaineMathInit;
    }
float RayTracing::getT(void)
    {
    return t;
    }

string RayTracing::getTitle(void)
    {
    return title;
    }
int RayTracing::getW(void)
    {
    return w;
    }
int RayTracing::getH(void)
    {
    return h;
    }

float RayTracing::randomMinMax(float min, float max)
    {
    return (max-min)*((float)(rand())/(float)RAND_MAX) + min;
    }

__host__ ConstantMemoryLink constantMemoryLink(void)
    {
    Sphere* ptrDevTabData;
    size_t sizeAll = LENGTH * sizeof(Sphere);
    HANDLE_ERROR(cudaGetSymbolAddress((void **) &ptrDevTabData, TAB_DATA_CM));
    ConstantMemoryLink cmLink =
       {
	       (void**) ptrDevTabData, LENGTH, sizeAll
       };
    return cmLink;
}

__host__ Sphere* instanciateSpheres(Sphere* ptrSpheres, int n)
    {
    ConstantMemoryLink cmLink = constantMemoryLink();
    Sphere* ptrDevSpheres = (Sphere*)cmLink.ptrDevTab;
    size_t sizeALL = cmLink.sizeAll;

    HANDLE_ERROR(cudaMemcpy(ptrDevSpheres, ptrSpheres, sizeALL, cudaMemcpyHostToDevice));

    return ptrDevSpheres;
    }

__host__ void destructSpheres(Sphere* ptrDevSpheres)
    {
    HANDLE_ERROR(cudaFree(ptrDevSpheres));
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
