#ifndef IMAGEFONCTIONELMOOS_A_H_
#define IMAGEFONCTIONELMOOS_A_H_


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

#ifndef CBI_NO_CUDA	 // pour compilation avec cuda

#include "ImageFonctionel_A_GPU.h"
#include "prioriteGPU.h"

#else // pour compilation sans cuda
#include "ImageFonctionel_A_CPU.h"
#include "prioriteCPU.h"

#endif

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
