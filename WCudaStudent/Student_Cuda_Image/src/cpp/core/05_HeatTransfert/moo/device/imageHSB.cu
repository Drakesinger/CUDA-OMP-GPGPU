#include <iostream>

#include "Indice2D.h"
#include "cudaTools.h"
#include "Device.h"
#include "IndiceTools.h"
#include "CalibreurF.h"
#include "ColorTools.h"

using std::cout;
using std::endl;

__global__ void heatImageHSB(float* ptrDevIn, uchar4* ptrDevOut,CalibreurF calibreur, int w, int h);

__global__ void heatImageHSB(float* ptrDevIn, uchar4* ptrDevOut,CalibreurF calibreur, int w, int h)
    {

    int tid = Indice2D::tid();
    int nbThread = Indice2D::nbThread();
    const int MAX = w*h;

    int s = tid;
    while(s < MAX)
	{
	ptrDevOut[s].w = 255;
	calibreur.calibrer(ptrDevIn[s]);
	ColorTools::HSB_TO_RVB(ptrDevIn[s], 1.0f, 1.0f, &ptrDevOut[s]);
	s += nbThread;
	}
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
