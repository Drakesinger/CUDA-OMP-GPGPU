#include <iostream>

#include "Indice2D.h"
#include "cudaTools.h"
#include "Device.h"
#include "IndiceTools.h"

using std::cout;
using std::endl;

__global__ void heatDiffusion(float* ptrDevIn, float* ptrDevOut,float k, int w, int h);

__global__ void heatDiffusion(float* ptrDevIn, float* ptrDevOut,float k, int w, int h)
    {

    int tid = Indice2D::tid();
    int nbThread = Indice2D::nbThread();
    const int MAX = (w-2)*(h-2);

    int s = tid;
    while(s < MAX)
	{
	int C = s + w + 1; //Offset
	ptrDevOut[C] = ptrDevIn[C] + k * (ptrDevIn[C - w] + ptrDevIn[C - 1] + ptrDevIn[C + w] + ptrDevIn[C + 1] - 4*ptrDevIn[C]);
	s += nbThread;
	}
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/