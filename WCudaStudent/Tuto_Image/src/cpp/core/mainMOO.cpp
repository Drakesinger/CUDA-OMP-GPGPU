#include <iostream>
#include <stdlib.h>

#include "WarmupProvider.h"
#include "VagueProvider.h"
#include "DamierProvider.h"
#include "AdvancedProvider.h"
#include "AdvancedDomaineProvider.h"

#include "Animateur.h"
#include "AnimateurFonctionel.h"

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

int mainMOO(void);

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

/**
 * xeon home 8 | i7 work 6 | i7 home 6
 *
 * 	fps
 *
 * 	omp auto / entrelacement
 *
 */
int mainMOO(void)
    {
    cout << "\n[FreeGL] mode" << endl;

    const int NB_ITERATION = 1000;

    // Warmup
	{
	Animable_I* ptrWarmup = WarmupProvider::createMOO();
	animer(ptrWarmup, NB_ITERATION);
	}

    // Vague
	{
	Animable_I* ptrVague = VagueProvider::createMOO();
	animer(ptrVague, NB_ITERATION);
	}

    //Damier
	{
	AnimableFonctionel_I* ptrDamier = DamierProvider::createMOO();
	animer(ptrDamier, NB_ITERATION);
	}

    // Advanced
	{
	Animable_I* ptrAdvanced = AdvancedProvider::createMOO();
	animer(ptrAdvanced, NB_ITERATION);
	}

	// Advanced domaine
	{
	AnimableFonctionel_I* ptrAdvancedDomain = AdvancedDomaineProvider::createMOO();
	animer(ptrAdvancedDomain, NB_ITERATION);
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

