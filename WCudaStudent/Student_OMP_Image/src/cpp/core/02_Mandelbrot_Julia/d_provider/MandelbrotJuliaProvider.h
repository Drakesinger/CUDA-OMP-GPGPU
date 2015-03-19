#ifndef MANDELBROTJULIA_PROVIDER_H_
#define MANDELBROTJULIA_PROVIDER_H_

#include "ImageFonctionel.h"
#include "AnimableFonctionel_I.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class MandelbrotJuliaProvider
    {
    public:

	static ImageFonctionel* createGL(void);
	static AnimableFonctionel_I* createMOO(void);

    };

#endif

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

