#include "AdvancedDomaineProvider.h"
#include "ImageFonctionelDomaine.h"
#include "DamierProvider.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*-----------------*\
 |*	static	   *|
 \*----------------*/

ImageFonctionel* AdvancedDomaineProvider::createGL(void)
    {
    AnimableFonctionel_I*  ptrMOO=AdvancedDomaineProvider::create();

    return new ImageFonctionelDomaine(ptrMOO);
    }

AnimableFonctionel_I* AdvancedDomaineProvider::create(void)
    {
    return DamierProvider::create();
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/