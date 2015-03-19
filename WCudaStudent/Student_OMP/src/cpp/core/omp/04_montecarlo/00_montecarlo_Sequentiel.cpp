#include <iostream>
#include <stdio.h>
#include "omp.h"
#include "OmpTools.h"
#include <string>

#include "../04_montecarlo/monteCarlotools.h"
#include "math.h"

using std::cout;
using std::endl;
using namespace std;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/
bool isMonteCarlo_sequentiel_Ok(int);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/
double ompMonteCarlo_sequentiel(int);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*-----------------------------------ca---*\
 |*		Public			*|
 \*-------------------------------------*/
bool isMonteCarlo_sequentiel_Ok(int n)
    {
    return isAlgo_OK(ompMonteCarlo_sequentiel,  n, "Pi OMP sequentiel");
    }


/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/
/**
 * pattern cuda : excellent!
 */
double ompMonteCarlo_sequentiel(int n)
    {
    // Permet de séléctionner le max de coeur disponible
    int ntot = 0;
    double px, py;

    for(int i=0; i<n;i++)
	{
	    px = OmpTools::uniform(0,1);
	    py = OmpTools::uniform(0,1);

	    if(py<=f_montecarlo(px))
		{
		    ntot++;
		}
	}
    return 4* (ntot / (double)n);
 }
/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

