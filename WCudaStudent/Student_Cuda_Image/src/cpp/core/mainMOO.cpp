#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "Animateur.h"
#include "AnimateurFonctionel.h"

#include "RipplingProvider.h"
#include "MandelbrotProvider.h"
#include "NewtonProvider.h"
#include "RayTracingSMProvider.h"
#include "HeatTransfertProvider.h"


using std::cout;
using std::endl;
using std::string;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int mainFreeGL(void);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static void animer(Animable_I* ptrAnimable, int nbIteration);
static void animer(AnimableFonctionel_I* ptrAnimable, int nbIteration);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int mainFreeGL(void)
    {
    cout << "\n[FreeGL] mode" << endl;

    const int NB_ITERATION = 1000;

    // Rippling
	{
	//Animable_I* ptrRippling = RipplingProvider::createMOO();
	//animer(ptrRippling, NB_ITERATION);

	//Animable_I* ptrMandelbrot = MandelbrotProvider::createMOO();
	//animer(ptrMandelbrot, NB_ITERATION);

	//AnimableFonctionel_I* ptrNewton = NewtonProvider::create();
    	//animer(ptrNewton, NB_ITERATION);

	//Animable_I* ptrRayTracingSM = RayTracingSMProvider::create();
	//animer(ptrRayTracingSM, NB_ITERATION);

	//Animable_I* ptrHeatTransfert = HeatTransfertProvider::create();
    	//animer(ptrHeatTransfert, NB_ITERATION);

	AnimableFonctionel_I* ptrMandelBrot = MandelbrotProvider::create();
    	animer(ptrMandelBrot, NB_ITERATION);
	}

    cout << "\n[FreeGL] end" << endl;

    return EXIT_SUCCESS;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

void animer(Animable_I* ptrAnimable, int nbIteration)
    {
    Animateur animateur(ptrAnimable, nbIteration);
    animateur.run();

    delete ptrAnimable;
    }

void animer(AnimableFonctionel_I* ptrAnimable, int nbIteration)
    {
    AnimateurFonctionel animateur(ptrAnimable, nbIteration);
    animateur.run();

    delete ptrAnimable;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

