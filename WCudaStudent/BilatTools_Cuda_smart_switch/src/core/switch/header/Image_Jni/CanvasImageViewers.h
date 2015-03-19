#ifndef CANVAS_NATIVE_IMAGE_VIEWERS_H_
#define CANVAS_NATIVE_IMAGE_VIEWERS_H_


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

#ifndef CBI_NO_CUDA	 // pour compilation avec cuda

#include "CanvasImageViewers_GPU.h"
#include "prioriteGPU.h"

#else // pour compilation sans cuda
#include "CanvasImageViewers_CPU.h"
#include "prioriteCPU.h"

#endif // CBI_NO_CUDA


#endif //  CANVAS_NATIVE_IMAGE_VIEWERS_H_

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
