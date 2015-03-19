#ifndef ADVANCED_PROVIDER_H_
#define ADVANCED_PROVIDER_H_

#include "Advanced.h"
#include "AdvancedImage.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class AdvancedProvider
    {
    public:

	static Advanced* create(void);
	static AdvancedImage* createGL(void);

    };

#endif

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

