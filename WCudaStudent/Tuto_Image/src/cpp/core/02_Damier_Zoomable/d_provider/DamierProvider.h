#ifndef DAMIER_PROVIDER_H_
#define DAMIER_PROVIDER_H_

#include "ImageFonctionel.h"
#include "AnimableFonctionel_I.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class DamierProvider
    {
    public:

	static ImageFonctionel* createGL(void);
	static AnimableFonctionel_I* createMOO(void);

    };

#endif

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

