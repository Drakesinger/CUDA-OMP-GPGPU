#include "VagueProvider.h"
#include "VagueMOO.h"

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

Image* VagueProvider::createGL(void)
    {
    Animable_I* ptrAnimable = VagueProvider::createMOO();

    return new Image(ptrAnimable);
    }

Animable_I* VagueProvider::createMOO(void)
    {
    int dw = 16 * 60 * 2; // =32*30=960
    int dh = 16 * 60; // =32*30=960

    float dt = 2 * PI / 200; // animation para

    return new VagueMOO(dw, dh, dt);
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
