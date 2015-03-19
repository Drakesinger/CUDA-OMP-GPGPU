#include <iostream>
#include <math.h>

#include "DamierMOO.h"

#include "OmpTools.h"
#include "MathTools.h"

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

/**
 * variateurT: 	fait varier t in [0,2pi] par increment de dt,
 * 		d'abord de manière croissante jusqua 2PI, puis de maniere decroissante jusqua 0, puis en boucle a l'infini selon ce procede
 */
DamierMOO::DamierMOO(unsigned int w, unsigned int h, float dt, int n):variateurT(IntervalF(0, 2 * PI), dt)
    {
    // Inputs
    this->n =n;
    this->w=w;
    this->h=h;
    this->domaineMathInit=DomaineMath(0, 0, 2 * PI, 2 * PI);

    // Outputs
    this->title="Damier_OMP (Zoomable)";

    //Tools
    this->isEntrelacement=true;

    // OMP (facultatif)
    const int NB_THREADS = OmpTools::setAndGetNaturalGranularity();
    cout << "\n[DAMIER] nbThread = " << NB_THREADS << endl;;
    }

DamierMOO::~DamierMOO(void)
    {
    // rien
    }

/*--------------------------------------*\
 |*		Override		*|
 \*-------------------------------------*/

/**
 * Override
 */
void DamierMOO::process(uchar4* ptrTabPixels, int w, int h, const DomaineMath& domaineMath)
    {
    if (isEntrelacement)
	{
	entrelacementOMP(ptrTabPixels,w,h,domaineMath); // Plus lent
	}
    else
	{
	forAutoOMP(ptrTabPixels,w,h,domaineMath);  // Plus rapide
	}

    isEntrelacement=!isEntrelacement; // Pour tester que les deux implementations fonctionnent

    // Note : Des saccades peuvent apparaitre à cause de la grande difference de fps entre la version entrelacer et auto
    }

/**
 * Override
 */
void DamierMOO::animationStep()
    {
    variateurT.varierAndGet();
    }

/*--------------*\
 |*	get	*|
 \*-------------*/

/**
 * Override
 */
float DamierMOO::getAnimationPara()
    {
    return variateurT.get();
    }

/**
 * Override
 */
string DamierMOO::getTitle()
    {
    return title;
    }

/**
 * Override
 */
int DamierMOO::getW()
    {
    return w;
    }

/**
 * Override
 */
int DamierMOO::getH()
    {
    return h;
    }

/**
 * Override
 */
DomaineMath* DamierMOO::getDomaineMathInit(void)
    {
    return &domaineMathInit;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/


/**
 * Code naturel et direct OMP
 */
void DamierMOO::forAutoOMP(uchar4* ptrTabPixels, int w, int h, const DomaineMath& domaineMath)
    {
    DamierMath damierMath(n); // ici pour preparer cuda

#pragma omp parallel for
    for (int i = 0; i < h; i++)
	{
	for (int j = 0; j < w; j++)
	    {
	    //int s = i * W + j;
	    int s=IndiceTools::toS(w,i,j);// i[0,H[ j[0,W[  --> s[0,W*H[

	    workPixel(&ptrTabPixels[s],i, j,s, domaineMath,&damierMath);
	    }
	}
    }

/**
 * Code entrainement Cuda
 */
void DamierMOO::entrelacementOMP(uchar4* ptrTabPixels, int w, int h, const DomaineMath& domaineMath)
    {
    DamierMath damierMath(n); // ici pour preparer cuda

    const int WH=w*h;

#pragma omp parallel
	{
	const int NB_THREAD = OmpTools::getNbThread(); // dans region parallel

	const int TID = OmpTools::getTid();
	int s = TID; // in [0,...

	int i;
	int j;
	while (s < WH)
	    {
	    IndiceTools::toIJ(s,w,&i,&j); // s[0,W*H[ --> i[0,H[ j[0,W[

	    workPixel(&ptrTabPixels[s],i, j,s, domaineMath,&damierMath);

	    s += NB_THREAD;
	    }
	}
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/**
 * i in [1,h]
 * j in [1,w]
 * code commun à
 * 	entrelacementOMP
 * 	forAutoOMP
 */
void DamierMOO::workPixel(uchar4* ptrColorIJ,int i, int j,int s, const DomaineMath& domaineMath,DamierMath* ptrDamierMath)
    {
    // (i,j) domaine ecran dans N2
    // (x,y) domaine math dans R2

    double x;
    double y;

    domaineMath.toXY(i, j, &x, &y); // fill (x,y) from (i,j)

    float t=variateurT.get();
    ptrDamierMath->colorXY(ptrColorIJ,x, y, domaineMath,t); // in [01]
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

