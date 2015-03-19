#ifndef CALIBREURF_PRIORITE_CUDA_H_
#define CALIBREURF_PRIORITE_CUDA_H_

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/


#ifndef CBI_NO_CUDA	 // pour compilation avec cuda

#include "CalibreurF_GPU.h"
#include "prioriteGPU.h"

#else // pour compilation avec cuda

#include "CalibreurF_CPU.h"
#include "prioriteCPU.h"

#endif


#endif

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/


