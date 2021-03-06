#include "ReductionTools.h"
#include <stdio.h>
#include <limits.h>
#include "curandTools.h"
#include "Device.h"

#ifndef SRC_CPP_CORE_03_MONTECARLO_DEVICE_MONTECARLO_CU_
#define SRC_CPP_CORE_03_MONTECARLO_DEVICE_MONTECARLO_CU_


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

__global__ void monteCarloDevice(float* ptrDevResult,curandState* ptrDevTabGeneratorThread,int nbFleche,int n);
__device__ void initSharedMemory(int* tabSM,int n);
__device__ void peuplerSharedMemory(int* tabSM,curandState* ptrDevTabGeneratorThread,int nbFleche);
/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

__global__ void monteCarloDevice(float* ptrDevResult,curandState* ptrDevTabGeneratorThread,int nbFleche,int n)
    {
    extern __shared__ int tabSM[];
	ReductionTools<int,float> reductionTools = ReductionTools<int,float>(n);
	initSharedMemory(tabSM,n);
	__syncthreads();
	peuplerSharedMemory(tabSM,ptrDevTabGeneratorThread,nbFleche);
	__syncthreads();
	reductionTools.reduction(tabSM,ptrDevResult);
	__syncthreads();
	const int TID = Indice1D::tid();
	if(TID==0)
	    {
	    *ptrDevResult=(*ptrDevResult/nbFleche)*4.0f;
	    }

    }
__device__ void initSharedMemory(int* tabSM,int n)
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
__device__ void peuplerSharedMemory(int* tabSM,curandState* ptrDevTabGeneratorThread,int nbFleche)
    {

	const int NB_THREAD=Indice1D::nbThread();
	const int TID = Indice1D::tid();
	const int TID_LOCAL = Indice1D::tidLocal();
	float s = TID;

	int somme=0;
	curandState localState = ptrDevTabGeneratorThread[TID];
	int tid = Indice1D::tid();


	while (s < nbFleche)
	    {
	    double x = curand_uniform(&localState);
	    double y = curand_uniform(&localState);
	    double z = 1.0 / (1.0 + x * x);
	    if (y < z)
		{
		somme += 1;
		}
	    s += NB_THREAD;
	    }

	tabSM[TID_LOCAL]=somme;
    }


#endif

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
