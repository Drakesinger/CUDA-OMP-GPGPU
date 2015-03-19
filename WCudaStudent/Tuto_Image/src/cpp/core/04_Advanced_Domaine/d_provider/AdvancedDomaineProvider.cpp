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
    AnimableFonctionel_I*  ptrMOO=AdvancedDomaineProvider::createMOO();

    return new ImageFonctionelDomaine(ptrMOO);
    }

AnimableFonctionel_I* AdvancedDomaineProvider::createMOO(void)
    {
    return DamierProvider::createMOO();
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
