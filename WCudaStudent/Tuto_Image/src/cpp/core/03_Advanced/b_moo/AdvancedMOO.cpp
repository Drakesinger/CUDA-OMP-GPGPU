#include <iostream>
#include <omp.h>

#include "AdvancedMOO.h"
#include "AdvancedMath.h"

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

AdvancedMOO::AdvancedMOO(unsigned int w, unsigned int h,float dt)
    {
    // Input
    this->w=w;
    this->h=h;
    this->dt=dt;

    // Tools
    this->t = 0;
    this->isEntrelacement=true;
    this->dt=1;

    // Outputs
    this->title="Advanced_OMP";


    // OMP (facultatif)
    const int NB_THREADS = OmpTools::setAndGetNaturalGranularity();
    cout << "\n[ADVANCED] nbThread = " << NB_THREADS << endl;
    }

AdvancedMOO::~AdvancedMOO(void)
    {
    // rien
    }

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * Override
 */
void AdvancedMOO::process(uchar4* ptrTabPixels, int w, int h)
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
void AdvancedMOO::animationStep()
    {
    t+=dt;
    }

/*--------------*\
 |*	get	*|
 \*-------------*/

/**
 * Override
 */
float AdvancedMOO::getAnimationPara()
    {
    return t;
    }

/**
 * Override
 */
string AdvancedMOO::getTitle()
    {
    return title;
    }

/**
 * Override
 */
int AdvancedMOO::getW()
    {
    return w;
    }

/**
 * Override
 */
int AdvancedMOO::getH()
    {
    return h;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/**
 * Code naturel et direct OMP
 */
void AdvancedMOO::forAutoOMP(uchar4* ptrTabPixels, int w, int h)
    {
    AdvancedMath advancedMath; // ici pour preparer cuda

#pragma omp parallel for
    for (int i = 0; i < h; i++)
	{
	for (int j = 0; j < w; j++)
	    {
	    // int s = i * W + j;
	    int s = IndiceTools::toS(w, i, j);    // i[0,H[ j[0,W[  --> s[0,W*H[

	    advancedMath.colorIJ(&ptrTabPixels[s], i, j);
	    }
	}
    }

/**
 * Code entrainement Cuda
 */
void AdvancedMOO::entrelacementOMP(uchar4* ptrTabPixels, int w, int h)
    {
    AdvancedMath advancedMath; // ici pour preparer cuda

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

	    advancedMath.colorIJ(&ptrTabPixels[s], i, j);

	    s += NB_THREAD;
	    }
	}
    }


/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

