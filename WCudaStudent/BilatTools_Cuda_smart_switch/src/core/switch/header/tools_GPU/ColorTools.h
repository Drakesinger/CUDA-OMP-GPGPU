#ifndef COLORTOOLS_PRIORITE_CUDA_H_
#define COLORTOOLS_PRIORITE_CUDA_H_

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

#ifndef CBI_NO_CUDA	 // pour compilation avec cuda

#include "ColorTools_GPU.h"
#include "prioriteGPU.h"

#else // pour compilation avec cuda

#include "IndiceTools_CPU.h"
#include "ColorTools_CPU.h"

#endif


#endif

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
