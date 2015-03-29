#include <iostream>
#include <assert.h>

#include "RayTracingSM.h"
#include "Device.h"

#include <math.h>
#include <limits>

#define BORD 200
#define LENGTH 500
__constant__ Sphere TAB_DATA_CM[LENGTH];


using std::cout;
using std::endl;
using std::string;

extern __global__ void rayTracing(uchar4* ptrDevPixels, int w, int h, Sphere* ptrDevSpheres, int length, float t);

RayTracingSM::RayTracingSM(int w, int h, float dt)
    {
    // Inputs
    this->w = w;
    this->h = h;
    this->t = 0;
    this->dt = dt;

    // Tools
    this->dg = dim3(16, 8, 1);
    this->db = dim3(32, 8, 1);

    // Outputs
    this->title = "RayTracingSM";

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

RayTracingSM::~RayTracingSM()
    {
    destructSpheres(ptrDevSpheres);
    delete[] ptrSpheres;
    }

/*-------------------------*\
 |*     Methode override    *|
 \*-------------------------*/

void RayTracingSM::process(uchar4* ptrDevPixels, int w, int h)
    {
    rayTracing<<<dg,db, LENGTH*sizeof(Sphere)>>>(ptrDevPixels, w, h, ptrDevSpheres,LENGTH ,t);
    }

float RayTracingSM::getAnimationPara(void)
    {
    return this->t;
    }

void RayTracingSM::animationStep()
    {
    this->t += dt;
    }

 /*--------------*\
 |* get override *|
 \*--------------*/
float RayTracingSM::getT(void)
    {
    return t;
    }

string RayTracingSM::getTitle(void)
    {
    return title;
    }
int RayTracingSM::getW(void)
    {
    return w;
    }
int RayTracingSM::getH(void)
    {
    return h;
    }

float RayTracingSM::randomMinMax(float min, float max)
    {
    return (max-min)*((float)(rand())/(float)RAND_MAX) + min;
    }

__host__ Sphere* RayTracingSM::instanciateSpheres(Sphere* ptrSpheres, int n)
    {
    Sphere *ptrDevSpheres;

    HANDLE_ERROR(cudaMalloc((void**)&ptrDevSpheres, sizeof(Sphere)*n));
    HANDLE_ERROR(cudaMemcpy(ptrDevSpheres, ptrSpheres, sizeof(Sphere)*n, cudaMemcpyHostToDevice));

    return ptrDevSpheres;
    }

__host__ void RayTracingSM::destructSpheres(Sphere* ptrDevSpheres)
    {
    HANDLE_ERROR(cudaFree(ptrDevSpheres));
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
