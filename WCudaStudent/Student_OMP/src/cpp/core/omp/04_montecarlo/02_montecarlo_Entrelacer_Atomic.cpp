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
bool isMonteCarlo_entrelacer_atomic_Ok(int);
/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/
double ompMonteCarlo_entrelacer_atomic(int);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*-----------------------------------ca---*\
 |*		Public			*|
 \*-------------------------------------*/
bool isMonteCarlo_entrelacer_atomic_Ok(int n)
    {
    return isAlgo_OK(ompMonteCarlo_entrelacer_atomic, n, "Pi OMP Entrelacer Atomic");
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/
/**
 * pattern cuda : excellent!
 */
double ompMonteCarlo_entrelacer_atomic(int n)
    {
    // Permet de séléctionner le max de coeur disponible
    const int NB_THREAD = OmpTools::setAndGetNaturalGranularity();
    double somme = 0;

    #pragma omp parallel
	{
	const int TID = OmpTools::getTid();
	int s = TID;
	double px, py;
	int sommeThread = 0;

	while (s < n)
	    {
	    px = OmpTools::uniform(0, 1);
	    py = OmpTools::uniform(0, 1);
	    if (py <= f_montecarlo(px))
		{
		sommeThread += 1;
		}
	    s += NB_THREAD;
	    }

	#pragma omp atomic
	    somme += sommeThread;
	}

    return 4 * (somme / (double) n);
    }
/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

