#include <iostream>
#include <omp.h>
#include <math.h>

#include "VagueMOO.h"
#include "VagueMath.h"

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

VagueMOO::VagueMOO(unsigned int w, unsigned int h, float dt)
    {
    // Input
    this->dt = dt;
    this->w = w;
    this->h = h;

    // Outputs
    this->title="Vague_OMP";

    // Tools
    this->t = 0;
    this->isEntrelacement = true;

    // OMP (facultatif)
    const int NB_THREADS = OmpTools::setAndGetNaturalGranularity();
    cout << "\n[VAGUE] nbThread = " << NB_THREADS << endl;
    }

VagueMOO::~VagueMOO(void)
    {
    // rien
    }

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * Override
 */
void VagueMOO::process(uchar4* ptrTabPixels, int w, int h)
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

    // Note : Des saccades peuvent apparaitre à cause de la grande difference de fps entre la version entrelacer et auto
    }

/**
 * Override
 */
void VagueMOO::animationStep()
    {
    t += dt;
    }

/*--------------*\
 |*	get	*|
 \*-------------*/

/**
 * Override
 */
float VagueMOO::getAnimationPara()
    {
    return t;
    }

/**
 * Override
 */
string VagueMOO::getTitle()
    {
    return title;
    }

/**
 * Override
 */
int VagueMOO::getW()
    {
    return w;
    }

/**
 * Override
 */
int VagueMOO::getH()
    {
    return h;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/**
 * Code naturel et direct OMP
 */
void VagueMOO::forAutoOMP(uchar4* ptrTabPixels, int w, int h)
    {
    VagueMath vagueMath(w, h); // ici pour preparer cuda

#pragma omp parallel for
    for (int i = 0; i < h; i++)
	{
	for (int j = 0; j < w; j++)
	    {
	    // int s = i * W + j;
	    int s = IndiceTools::toS(w, i, j);    // i[0,H[ j[0,W[  --> s[0,W*H[

	    vagueMath.colorIJ(&ptrTabPixels[s], i, j, t);
	    }
	}
    }

/**
 * Code entrainement Cuda
 */
void VagueMOO::entrelacementOMP(uchar4* ptrTabPixels, int w, int h)
    {
    VagueMath vagueMath(w, h); // ici pour preparer cuda

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

	    vagueMath.colorIJ(&ptrTabPixels[s], i, j, t);

	    s += NB_THREAD;
	    }
	}
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

