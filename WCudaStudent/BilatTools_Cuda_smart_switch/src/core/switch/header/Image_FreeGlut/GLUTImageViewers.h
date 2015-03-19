#ifndef GLUT_IMAGE_VIEWERS_H_
#define GLUT_IMAGE_VIEWERS_H_


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

#ifndef CBI_NO_CUDA // pour compilation avec cuda

#include "GLUTImageViewers_GPU.h"
#include "prioriteGPU.h"

#else // pour compilation sans cuda
#include "GLUTImageViewers_CPU.h"
#include "prioriteCPU.h"

#endif


#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
