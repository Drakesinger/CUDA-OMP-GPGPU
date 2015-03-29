#include <iostream>

#include "Indice2D.h"
#include "cudaTools.h"
#include "Device.h"
#include "IndiceTools.h"

#include "RayTracingSMMath.h"

using std::cout;
using std::endl;

__global__ void rayTracingSM(uchar4* ptrDevPixels, int w, int h, Sphere* ptrDevSpheres,int length, float t)
    {

    extern __shared__ Sphere tabSphereSM[];

    int tid = Indice2D::tid();
    int nbThread = Indice2D::nbThread();
    const int MAX = w*h;
    int s = threadIdx.x+blockDim.x*threadIdx.y;

    while(s< length)
	{
	tabSphereSM[s] = ptrDevSpheres[s];
	s += blockDim.x * blockDim.y;
	}
    __syncthreads();

    RayTracingSMMath rayTracingMath(ptrDevSpheres,length);

    int i,j;
    s = tid;


    while(s < MAX)
	{
	IndiceTools::toIJ(s,w,&i,&j);

	rayTracingMath.colorXY(j, i, t, &ptrDevPixels[s]);
	s += nbThread;
	}
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
