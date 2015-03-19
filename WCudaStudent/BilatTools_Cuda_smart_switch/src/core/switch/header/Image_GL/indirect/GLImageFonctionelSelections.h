#ifndef GLIMAGEFONCTIONELSELECTIONS_H_
#define GLIMAGEFONCTIONELSELECTIONS_H_


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

#ifndef CBI_NO_CUDA	 // pour compilation avec cuda

#include "GLImageFonctionelSelections_GPU.h"
#include "prioriteGPU.h"

#else // pour compilation sans cuda
#include "GLImageFonctionelSelections_CPU.h"
#include "prioriteCPU.h"

#endif


#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
