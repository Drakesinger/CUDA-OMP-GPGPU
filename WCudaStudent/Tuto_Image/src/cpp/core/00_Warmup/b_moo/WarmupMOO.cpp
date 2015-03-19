#include <iostream>
#include <omp.h>
#include <math.h>

#include "WarmupMOO.h"
#include "WarmupMath.h"

#include "OmpTools.h"
#include "IndiceTools.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

WarmupMOO::WarmupMOO(unsigned int w, unsigned int h, float dt)
    {
    // Input
    this->dt = dt;
    this->w=w;
    this->h=h;

    // Tools
    this->t = 0;
    this->isEntrelacement=true;

    // Outputs
    this->title="Warmup_OMP";

    // OMP (facultatif)
    const int NB_THREADS = OmpTools::setAndGetNaturalGranularity();
    cout << "\n[WARMUP] nbThread = " << NB_THREADS << endl;
    }

WarmupMOO::~WarmupMOO(void)
    {
    // rien
    }

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * Override
 * Call periodicly
 */
void WarmupMOO::process(uchar4* ptrTabPixels, int w, int h)
    {
    if (isEntrelacement)
	{
	entrelacementOMP(ptrTabPixels, w, h); // Plus lent
	}
    else
	{
	forAutoOMP(ptrTabPixels, w, h);  // Plus rapide
	}

    isEntrelacement = !isEntrelacement; // Pour tester que les deux implementations fonctionnent
    }

/**
 * Override
 * Call periodicly
 */
void WarmupMOO::animationStep()
    {
    t+=dt;
    }

/*--------------*\
 |*	get	*|
 \*-------------*/

/**
 * Override
 */
float WarmupMOO::getAnimationPara()
    {
    return t;
    }

/**
 * Override
 */
string WarmupMOO::getTitle()
    {
    return title;
    }

/**
 * Override
 */
int WarmupMOO::getW()
    {
    return w;
    }

/**
 * Override
 */
int WarmupMOO::getH()
    {
    return h;
    }


/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/**
 * Code naturel et direct OMP
 */
void WarmupMOO::forAutoOMP(uchar4* ptrTabPixels, int w, int h)
    {
    WarmupMath warmupMath(w,h); // ici pour preparer cuda

#pragma omp parallel for
    for (int i = 0; i < h; i++)
	{
	for (int j = 0; j < w; j++)
	    {
	    // int s = i * W + j;
	    int s = IndiceTools::toS(w, i, j);    // i[0,H[ j[0,W[  --> s[0,W*H[

	    warmupMath.colorIJ(&ptrTabPixels[s], i, j, t);
	    }
	}
    }

/**
 * Code entrainement Cuda
 */
void WarmupMOO::entrelacementOMP(uchar4* ptrTabPixels, int w, int h)
    {
    WarmupMath warmupMath(w,h); // ici pour preparer cuda

    const int WH = w * h;

#pragma omp parallel
	{
	const int NB_THREAD = OmpTools::getNbThread(); // dans region parallel

	const int TID = OmpTools::getTid();
	int s = TID; // in [0,...

	int i;
	int j;
	while (s < WH)
	    {
	    IndiceTools::toIJ(s, w, &i, &j); // s[0,W*H[ --> i[0,H[ j[0,W[

	    warmupMath.colorIJ(&ptrTabPixels[s], i, j,t);

	    s += NB_THREAD;
	    }
	}
    }


/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

