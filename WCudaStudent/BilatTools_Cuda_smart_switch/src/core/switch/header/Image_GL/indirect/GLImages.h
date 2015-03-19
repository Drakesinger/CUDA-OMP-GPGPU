#ifndef GLIMAGES_H_
#define GLIMAGES_H_


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

#ifndef CBI_NO_CUDA	 // pour compilation avec cuda

#include "GLImages_GPU.h"
#include "prioriteGPU.h"

#else // pour compilation sans cuda
#include "GLImages_CPU.h"
#include "prioriteCPU.h"

#endif

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
