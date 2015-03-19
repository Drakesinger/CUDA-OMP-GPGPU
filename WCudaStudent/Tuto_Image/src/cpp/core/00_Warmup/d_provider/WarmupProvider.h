#ifndef WARMUP_PROVIDER_H_
#define WARMUP_PROVIDER_H_


#include "Animable_I.h"
#include "WarmupImage.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class WarmupProvider
    {
    public:

	static WarmupImage* createGL(void);
	static Animable_I* createMOO(void);

    };

#endif

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

