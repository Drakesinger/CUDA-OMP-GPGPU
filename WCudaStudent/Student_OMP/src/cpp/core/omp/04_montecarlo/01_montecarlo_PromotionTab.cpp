#include <stdio.h>
#include <iostream>
#include <string>
#include "../../../../../../BilatTools_OMP/src/core/OMP_Tools/header/OmpTools.h"
#include "../04_montecarlo/monteCarlotools.h"
#include "math.h"
#include "omp.h"

using std::cout;
using std::endl;
using namespace std;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/
bool isMonteCarlo_promotiontab_Ok(int);
/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/
double ompMonteCarlo(int);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*-----------------------------------ca---*\
 |*		Public			*|
 \*-------------------------------------*/
bool isMonteCarlo_promotiontab_Ok(int n)
    {
    return isAlgo_OK(ompMonteCarlo, n, "Pi OMP Entrelacer promotionTab");
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/
/**
 * pattern cuda : excellent!
 */
double ompMonteCarlo(int n)
    {
    const int NB_THREAD = OmpTools::setAndGetNaturalGranularity();
    int* tabSomme = new int[NB_THREAD];

#pragma omp parallel
	{
	const int TID = OmpTools::getTid();
	int s = TID;
	double px, py;
	tabSomme[TID] = 0;

	while (s < n)
	    {
	    px = OmpTools::uniform(0, 1);
	    py = OmpTools::uniform(0, 1);
	    if (py <= f_montecarlo(px))
		{
		tabSomme[TID] += 1;
		}
	    s += NB_THREAD;
	    }
	}

    //réduction
    int somme = 0;
    for (int i = 0; i < NB_THREAD; i++)
	{
	somme += tabSomme[i];
	}

    delete[] tabSomme;
    return 4 * (somme / (double) n);
    }
/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

