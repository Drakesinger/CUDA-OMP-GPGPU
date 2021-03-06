#include "NewtonProvider.h"
#include "MathTools.h"
#include "DomaineMath.h"
#include <limits>

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

Newton* NewtonProvider::create()
    {
    int dw = 300;
    int dh = 300;

    int nMin = 0;
    int nMax = 100;

    float dt = 0.1;
    float epsilon = std::numeric_limits<float>::epsilon();

    DomaineMath *domaineMath = new DomaineMath(-2, -2, 2, 2);
    return new Newton(dw, dh, domaineMath, nMin, nMax, dt, epsilon);
    }

ImageFonctionel* NewtonProvider::createGL(void)
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
