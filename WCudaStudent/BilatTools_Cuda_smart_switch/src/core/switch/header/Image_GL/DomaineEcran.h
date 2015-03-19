#ifndef DOMAINEECRAN_H_
#define DOMAINEECRAN_H_


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

#ifndef CBI_NO_CUDA	 // pour compilation avec cuda

#include "DomaineEcran_GPU.h"
#include "prioriteGPU.h"

#else // pour compilation sans cuda
#include "DomaineEcran_CPU.h"
#include "prioriteCPU.h"

#endif


#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
