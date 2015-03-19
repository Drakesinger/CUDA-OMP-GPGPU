#ifndef INDICE_TOOLS_PRIORITE_CUDA_H_
#define INDICE_TOOLS_PRIORITE_CUDA_H_

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/


#ifndef CBI_NO_CUDA	 // pour compilation avec cuda

#include "IndiceTools_GPU.h"
#include "prioriteGPU.h"

#else // pour compilation avec cuda

#include "IndiceTools_CPU.h"
#include "prioriteCPU.h"

#endif


#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
