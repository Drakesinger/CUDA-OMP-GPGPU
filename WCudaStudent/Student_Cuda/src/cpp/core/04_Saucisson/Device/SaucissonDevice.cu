#include "ReductionTools.h"
#include <stdio.h>
#ifndef SRC_CPP_CORE_03_SAUCISSON_DEVICE_SAUCISSONDEVICE_CU_
#define SRC_CPP_CORE_03_SAUCISSON_DEVICE_SAUCISSONDEVICE_CU_


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

__global__ void saucissonDevice(float* ptrDevResult,int nbSaucisson,int n);
__device__ void initSM(float* tabSM,int n);
__device__ void peuplerSM(float* tabSM,int nbSaucisson);
__device__ float fpi(float x);
/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

__global__ void saucissonDevice(float* ptrDevResult,int nbSaucisson,int n)
    {
    extern __shared__ float tabSM[];
	ReductionTools<float,float> reductionTools = ReductionTools<float,float>(n);
	initSM(tabSM,n);
	__syncthreads();
	peuplerSM(tabSM,nbSaucisson);
	__syncthreads();
	reductionTools.reduction(tabSM,ptrDevResult);


    }
__device__ void initSM(float* tabSM,int n)
    {
	const int TID_LOCAL = Indice1D::tidLocal();
	const int NB_THREAD_LOCAL= Indice1D::nbThreadBlock();
	int s = TID_LOCAL;
	while(s<n)
	    {
	    tabSM[s]=0;
	    s+=NB_THREAD_LOCAL;
	    }
    }
__device__ void peuplerSM(float* tabSM,int nbSaucisson)
    {
	const int NB_THREAD=Indice1D::nbThread();
	const int TID = Indice1D::tid();
	const int TID_LOCAL = Indice1D::tidLocal();
	const float DX = 1/(float)nbSaucisson;
	float s = TID;
	float somme=0;
	while (s < nbSaucisson)
	    {
	    double xs = s * DX;
	    somme += fpi(xs);
	    s += NB_THREAD;
	    }
	//printf("%f",somme);
	tabSM[TID_LOCAL]=somme;


    }

__device__
float fpi(float x)
    {
    return (float)4 / (float)(1 + x * x);
    }

#endif

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
