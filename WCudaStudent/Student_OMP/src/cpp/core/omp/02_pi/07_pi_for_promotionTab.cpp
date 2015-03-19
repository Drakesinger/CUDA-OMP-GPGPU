#include <omp.h>
#include "00_pi_tools.h"
#include "MathTools.h"
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

bool isPiOMPforPromotionTab_Ok(int n);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static double piOMPforPromotionTab(int n);
static void syntaxeSimplifier(double* tabSumThread,int n);
static void syntaxeFull(double* tabSumThread,int n);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

bool isPiOMPforPromotionTab_Ok(int n)
    {
    return isAlgoPI_OK(piOMPforPromotionTab, n, "Pi OMP for promotion tab");
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/**
 * De-synchronisation avec PromotionTab
 */
double piOMPforPromotionTab(int n)
    {
    // Permet de séléctionner le max de coeur disponible
        const int NB_THREAD = OmpTools::setAndGetNaturalGranularity();
        const double dx = 1 / (double)n;

        double* tabSomme = new double[NB_THREAD];

        for (int i = 0; i<NB_THREAD; i++){
            tabSomme[i] = 0;
        }

        #pragma omp parallel for

        for (int i = 0; i<n; i++)
		{
		    double xs = i * dx;
		    tabSomme[OmpTools::getTid()] += fpi(xs);

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

