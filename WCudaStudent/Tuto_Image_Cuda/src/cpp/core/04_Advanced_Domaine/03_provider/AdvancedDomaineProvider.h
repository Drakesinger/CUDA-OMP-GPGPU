#ifndef ADVANCED_DOMAINE_PROVIDER_H_
#define ADVANCED_DOMAINE_PROVIDER_H_

#include "ImageFonctionel.h"
#include "AnimableFonctionel_I.h"


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class AdvancedDomaineProvider
    {
    public:

	static ImageFonctionel* createGL(void);

	static AnimableFonctionel_I* create(void);

    };

#endif

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

