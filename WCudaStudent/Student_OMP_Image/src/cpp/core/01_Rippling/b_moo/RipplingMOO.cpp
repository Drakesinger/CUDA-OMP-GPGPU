#include <iostream>
#include <omp.h>

#include "RipplingMOO.h"
#include "RipplingMath.h"
#include "OmpTools.h"
#include "IndiceTools.h"

using std::cout;
using std::endl;
using std::string;

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

RipplingMOO::RipplingMOO(unsigned int w, unsigned int h, float dt)
    {
    // Inputs
    this->w=w;
    this->h=h;
    this->dt=dt;

    // Tools
    this->t=0;
    this->isEntrelacement = true;
    }

RipplingMOO::~RipplingMOO(void)
    {
    // rien
    }


/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * Override
 */
void RipplingMOO::process(uchar4* ptrTabPixels, int w, int h)
    {
    if (isEntrelacement)
	{
	entrelacementOMP(ptrTabPixels,w,h); // Plus lent
	}
    else
	{
	forAutoOMP(ptrTabPixels,w,h);  // Plus rapide
	}

    isEntrelacement=!isEntrelacement;// Pour tester que les deux implementations fonctionnent
    }

/**
 * Override
 */
void RipplingMOO::animationStep()
    {
    t+=dt;
    }

/*--------------*\
 |*	get	*|
 \*-------------*/

/**
 * Override
 */
float RipplingMOO::getAnimationPara()
    {
    return t;
    }

/**
 * Override
 */
int RipplingMOO::getW()
    {
    return w;
    }

/**
 * Override
 */
int RipplingMOO::getH()
    {
    return h;
    }

/**
 * Override
 */
string RipplingMOO::getTitle()
    {
    return "Rippling_OMP";
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/**
 * Code entrainement Cuda
 */
void RipplingMOO::entrelacementOMP(uchar4* ptrTabPixels,int w,int h)
    {
    RipplingMath ripplingMath(w,h); // ici pour preparer cuda

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

    	    ripplingMath.colorIJ(&ptrTabPixels[s], i, j,t);

    	    s += NB_THREAD;
    	    }
    	}
    }

/**
 * Code naturel et direct OMP
 */
void RipplingMOO::forAutoOMP(uchar4* ptrTabPixels,int w,int h)
    {
       RipplingMath ripplingMath(w, h);

   #pragma omp parallel for
       for (int i = 0; i < h; i++)
   	{
   	for (int j = 0; j < w; j++)
   	    {
   	    // int s = i * W + j;
   	    int s = IndiceTools::toS(w, i, j);    // i[0,H[ j[0,W[  --> s[0,W*H[

   	    ripplingMath.colorIJ(&ptrTabPixels[s], i, j, t);
   	    }
   	}
    }



/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
