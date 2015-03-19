#include <iostream>
#include <math.h>
#include <cstdlib>
#include <stdlib.h>

#include "AleaTools.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructor		*|
 \*-------------------------------------*/

AleaTools::AleaTools()
    {
    srand(time(NULL));
    }

AleaTools::~AleaTools()
    {
    // rien
    }

/*--------------------------------------*\
 |*		Methodes		*|
 \*-------------------------------------*/

/*----------------------*\
 |*	static		*|
 \*---------------------*/

/**
 * in [a,b]
 * Attention : pas thread safe
 */
double AleaTools::uniformeAB(double a, double b)
    {
    return a + uniforme01() * (b - a);
    }

/**
 * in [0,1]
 * Attention : pas thread safe
 */
double AleaTools::uniforme01(void)
    {
    // rand in [0,RAND_MAX]
    return rand() / (double) RAND_MAX;
    }

/**
 * in [a,b]
 * Attention : pas thread safe
 */
int AleaTools::uniformeAB(int a, int b)
    {
    // rand in [0,RAND_MAX]
    double pente = (b-a)/(double)RAND_MAX;

    return a+(int)(pente*rand());
    }


/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

