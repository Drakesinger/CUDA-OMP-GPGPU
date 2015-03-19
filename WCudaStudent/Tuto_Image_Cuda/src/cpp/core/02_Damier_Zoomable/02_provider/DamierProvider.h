#ifndef DAMIER_PROVIDER_H_
#define DAMIER_PROVIDER_H_

#include "Damier.h"
#include "ImageFonctionel.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class DamierProvider
    {
    public:

	static Damier* create(void);
	static ImageFonctionel* createGL(void);
    };

#endif

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

