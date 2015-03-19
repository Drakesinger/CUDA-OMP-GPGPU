#include "MandelbrotProvider.h"
#include "MathTools.h"
#include "DomaineMath.h"

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

Mandelbrot* MandelbrotProvider::create()
    {
    int dw = 16 * 80;
    int dh = 16 * 60;

    int nMin = 40;
    int nMax = 230;

    float dt = 0.1;
    DomaineMath *domaineMath = new DomaineMath(-1.3968, -0.03362, -1.3578, 0.0013973);
    return new Mandelbrot(dw, dh, domaineMath, nMin, nMax, dt);
    }

ImageFonctionel* MandelbrotProvider::createGL(void)
    {
    ColorRGB_01* ptrColorTitre = new ColorRGB_01(255, 0, 0);
    return new ImageFonctionel(create(),ptrColorTitre);
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/