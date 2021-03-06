#include "WarmupProvider.h"
#include "MathTools.h"

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

Warmup* WarmupProvider::create()
    {
    float dt = 2 * PI / 1000;

    int dw = 16 * 60 * 2; // =32*30=960
    int dh = 16 * 60; // =32*30=960

    return new Warmup(dw, dh, dt);
    }

WarmupImage* WarmupProvider::createGL(void)
    {
    float dt = 2 * PI / 1000;

    int dw = 16 * 60 * 2; // =32*30=960
    int dh = 16 * 60; // =32*30=960

    return new WarmupImage(dw, dh, dt);
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

