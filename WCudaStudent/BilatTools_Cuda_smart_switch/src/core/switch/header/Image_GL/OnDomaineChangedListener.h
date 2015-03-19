#ifndef ONDOMAINECHANGEDLISTENER_H_
#define ONDOMAINECHANGEDLISTENER_H_



/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

#ifndef CBI_NO_CUDA	 // pour compilation avec cuda

#include "OnDomaineChangedListener_GPU.h"
#include "prioriteGPU.h"

#else // pour compilation sans cuda
#include "OnDomaineChangedListener_CPU.h"
#include "prioriteCPU.h"

#endif

#endif 


/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
