#include <omp.h>
#include "00_pi_tools.h"
#include "OmpTools.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

bool isPiOMPEntrelacerCritical_Ok(int n);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static double piOMPEntrelacerCritical(int n);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

bool isPiOMPEntrelacerCritical_Ok(int n)
    {
    return isAlgoPI_OK(piOMPEntrelacerCritical, n, "Pi OMP Entrelacer critical");
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

double piOMPEntrelacerCritical(int n)
    {
    // Permet de séléctionner le max de coeur disponible
    const int NB_THREAD = OmpTools::setAndGetNaturalGranularity();
    const double dx = 1 / (double)n;


    double somme = 0;
    #pragma omp parallel
    {
	const int TID = OmpTools::getTid();
	int s = TID;

	double sommeThread = 0;

	while(s < n)
	    {
		double xs = s * dx;
		sommeThread += fpi(xs);

		s+= NB_THREAD;
	    }

	#pragma omp critical (caraccio)
	    {
		somme += sommeThread;
	    }
    }
        return somme / n;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

