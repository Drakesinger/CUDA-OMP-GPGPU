#ifndef INTERVALF_PRIORITE_CUDA_H_
#define INTERVALF_PRIORITE_CUDA_H_

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/


#ifndef CBI_NO_CUDA	 // pour compilation avec cuda

#include "IntervalF_GPU.h"
#include "prioriteGPU.h"

#else // pour compilation avec cuda

#include "IntervalF_CPU.h"
#include "prioriteCPU.h"

#endif


#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

