#include "Indice2D.h"
#include "cudaTools.h"
#include <iostream>

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/


__host__ void addVecteur(void);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static __global__ void addVecteur(float* ptrDevV1, float* ptrDevV2, float* ptrDevW,int n);
static __device__ void secondaire(float* ptrDevV1, float* ptrDevV2, float* ptrDevW,int n);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/


/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

__host__ void addVecteur(void)
    {
    int n=9;
    float* ptrV1 = new float[n];
    float* ptrV2 = new float[n];
    float* ptrW = new float[n];

    for(int i=0; i<n; i++)
	{
	ptrV1[i]=i+1;
	ptrV2[i]=(i+1)*10;
	}

    float* ptrDevV1= NULL;
    float* ptrDevV2= NULL;
    float* ptrDevW=NULL;
    size_t size=n*sizeof(float);

    HANDLE_ERROR(cudaMalloc(&ptrDevV1, size));
    HANDLE_ERROR(cudaMalloc(&ptrDevV2, size));
    HANDLE_ERROR(cudaMalloc(&ptrDevW, size));

    HANDLE_ERROR(cudaMemset(ptrDevW, 0, size));

    HANDLE_ERROR(cudaMemcpy(ptrDevV1,ptrV1, size, cudaMemcpyHostToDevice));
    HANDLE_ERROR(cudaMemcpy(ptrDevV2,ptrV2, size, cudaMemcpyHostToDevice));

    dim3 dg(16,2,1);
    dim3 db(32,4,1);

    addVecteur<<<dg,db>>>(ptrDevV1, ptrDevV2, ptrDevW, n);

    HANDLE_ERROR(cudaMemcpy(ptrW,ptrDevW, size, cudaMemcpyDeviceToHost));

    HANDLE_ERROR(cudaFree(ptrDevV1));
    HANDLE_ERROR(cudaFree(ptrDevV2));
    HANDLE_ERROR(cudaFree(ptrDevW));

    cout << endl;
    for(int i=0; i<n;i++)
	{
	cout << ptrW[i] << "\t";
	}
    cout << endl;
    delete[] ptrV1;
    delete[] ptrV2;
    delete[] ptrW;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

__global__ void addVecteur(float* ptrDevV1, float* ptrDevV2, float* ptrDevW,int n)
    {
    secondaire(ptrDevV1, ptrDevV2, ptrDevW, n);
    }

__device__ void secondaire(float* ptrDevV1, float* ptrDevV2, float* ptrDevW,int n)
    {
    const int NB_THREAD=Indice2D::nbThread();
    const int TID=Indice2D::tid();

    int s=TID;
    while(s<n)
	{
	ptrDevW[s]=ptrDevV1[s]+ptrDevV2[s];
	s+=NB_THREAD;
	}
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

