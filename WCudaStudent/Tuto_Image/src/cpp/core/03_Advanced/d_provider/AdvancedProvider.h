#ifndef EVENT_PROVIDER_H_
#define EVENT_PROVIDER_H_

#include "AdvancedImage.h"
#include "Animable_I.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class AdvancedProvider
    {
    public:

	static AdvancedImage* createGL(void);
	static Animable_I* createMOO(void);

    };

#endif

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

