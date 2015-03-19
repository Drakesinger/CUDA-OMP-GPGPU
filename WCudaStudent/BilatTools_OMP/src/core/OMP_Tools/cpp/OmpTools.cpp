#include <omp.h>
#include "OmpTools.h"

#define MULTIPLIER 1366
#define ADDEND  150889
#define PMOD  714025

long random_last = 0;
#pragma omp threadprivate(random_last)

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructor		*|
 \*-------------------------------------*/

OmpTools::OmpTools()
    {
    // rien
    }

OmpTools::~OmpTools()
    {
    // rien
    }

/*--------------------------------------*\
 |*		Methodes		*|
 \*-------------------------------------*/

/*----------------------*\
 |*	static	public	*|
 \*---------------------*/

int OmpTools::setAndGetNaturalGranularity()
    {
    // ko sur ARM, 1 core detecte only
//    {
//    int nbThread = omp_get_num_procs();
//    omp_set_num_threads(nbThread);
//    return nbThread;
//    }

#ifndef __arm__

    int nbThread = omp_get_num_procs();

#else

    //omp_get_num_procs ne donne pas la bonne valeurs sur kayla

    int nbThread=4;//4 car kayla à 4 coeurs.

#endif

    omp_set_num_threads(nbThread);
    return nbThread;
    }

/*--------*\
 |*  get  *|
 \*-------*/

int OmpTools::getNbCore()
    {
    return omp_get_num_procs();
    }

int OmpTools::getNbThread()
    {
    return omp_get_num_threads();
    }

int OmpTools::getTid()
    {
    return omp_get_thread_num();
    }

/*--------*\
 |*  set  *|
 \*-------*/

void OmpTools::setNbThread(int nbThread)
    {
    omp_set_num_threads(nbThread);
    }

/*--------*\
 |*  math  *|
 \*-------*/

double OmpTools::uniform01(void)
    {
    long random_next;

    random_next = (MULTIPLIER * random_last + ADDEND) % PMOD;
    random_last = random_next;

    return ((double) random_next / (double) PMOD);
    }

double OmpTools::uniform(double a, double b)
    {
    return a + uniform01() * (b - a);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

