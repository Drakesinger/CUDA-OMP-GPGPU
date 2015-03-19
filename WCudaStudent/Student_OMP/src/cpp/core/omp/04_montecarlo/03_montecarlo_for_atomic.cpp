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
bool isMonteCarlo_for_atomic_Ok(int);
/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/
double ompMonteCarlo_for_atomic(int);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*-----------------------------------ca---*\
 |*		Public			*|
 \*-------------------------------------*/
bool isMonteCarlo_for_atomic_Ok(int n)
    {
    return isAlgo_OK(ompMonteCarlo_for_atomic, n, "Pi OMP For Atomic");
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/
/**
 * pattern cuda : excellent!
 */
double ompMonteCarlo_for_atomic(int n)
    {
    int somme = 0;
    #pragma omp parallel for
        for (int i = 0; i<n; i++)
        {
            double px = OmpTools::uniform(0, 1);
            double py = OmpTools::uniform(0, 1);

            if (py <= f_montecarlo(px))
        	{
		#pragma omp atomic
		    somme += 1;
        	}

        }
        return 4 * (somme / (double) n);
    }
/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

