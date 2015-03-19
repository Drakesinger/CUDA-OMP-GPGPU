#include <iostream>
#include <stdlib.h>

#include "Animateur.h"
#include "AnimateurFonctionel.h"

#include "WarmupProvider.h"
#include "VagueProvider.h"
#include "DamierProvider.h"
#include "AdvancedProvider.h"
#include "AdvancedDomaineProvider.h"

using std::cout;
using std::endl;

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

    const int NB_ITERATION = 30000;

    // Warmup
	{
	Animable_I* ptrWarmup = WarmupProvider::create();
	animer(ptrWarmup, NB_ITERATION);
	}

    // Vague
	{
	Animable_I* ptrVague = VagueProvider::create();
	animer(ptrVague, NB_ITERATION);
	}

    // Damier
	{
	AnimableFonctionel_I* ptrDamier = DamierProvider::create();
	animer(ptrDamier, NB_ITERATION);
	}

    // Advanced
	{
	AnimableFonctionel_I* ptrAdvanced = AdvancedProvider::create();
	animer(ptrAdvanced, NB_ITERATION);
	}

    // Advanced Domaine
	{
	AnimableFonctionel_I* ptrAdvancedListener = AdvancedDomaineProvider::create();
	animer(ptrAdvancedListener, NB_ITERATION);
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

