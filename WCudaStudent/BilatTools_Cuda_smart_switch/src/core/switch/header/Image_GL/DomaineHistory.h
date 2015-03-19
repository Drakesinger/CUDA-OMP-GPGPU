#ifndef DOMAINE_HISTORY_H_
#define DOMAINE_HISTORY_H_

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/



/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/


#ifndef CBI_NO_CUDA	 // pour compilation avec cuda

#include "DomaineHistory_GPU.h"
#include "prioriteGPU.h"

#else // pour compilation sans cuda
#include "DomaineHistory_CPU.h"
#include "prioriteCPU.h"

#endif

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
