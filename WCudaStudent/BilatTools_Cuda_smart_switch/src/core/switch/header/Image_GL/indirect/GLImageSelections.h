#ifndef GLIMAGESELECTIONS_H_
#define GLIMAGESELECTIONS_H_


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

#ifndef CBI_NO_CUDA	 // pour compilation avec cuda

#include "GLImageSelections_GPU.h"
#include "prioriteGPU.h"

#else // pour compilation sans cuda
#include "GLImageSelections_CPU.h"
#include "prioriteCPU.h"

#endif

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
