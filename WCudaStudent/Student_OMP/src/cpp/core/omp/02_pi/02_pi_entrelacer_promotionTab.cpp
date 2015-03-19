#include <omp.h>

#include "../../../../../../BilatTools_OMP/src/core/OMP_Tools/header/OmpTools.h"
#include "00_pi_tools.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/


/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

bool isPiOMPEntrelacerPromotionTab_Ok(int n);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static double piOMPEntrelacerPromotionTab(int n);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

bool isPiOMPEntrelacerPromotionTab_Ok(int n)
    {
    return isAlgoPI_OK(piOMPEntrelacerPromotionTab,  n, "Pi OMP Entrelacer promotionTab");
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/**
 * pattern cuda : excellent!
 */
double piOMPEntrelacerPromotionTab(int n)
    {
    // Permet de séléctionner le max de coeur disponible
    const int NB_THREAD = OmpTools::setAndGetNaturalGranularity();
    const double dx = 1 / (double)n;

    double* tabSomme = new double[NB_THREAD];

    #pragma omp parallel
    {
	const int TID = OmpTools::getTid();
	int s = TID;

	tabSomme[TID] = 0;

	while(s < n){
	    double xs = s * dx;
	    tabSomme[TID] += fpi(xs);
	    s+= NB_THREAD;
	}
    }
    //réduction
    double somme = 0;
    for(int i = 0; i<NB_THREAD;i++){
	somme += tabSomme[i];
    }

    return somme / n;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

