#include "MandelbrotJuliaMOO.h"

#include <iostream>
#include <math.h>

#include "OmpTools.h"
#include "MathTools.h"

#include "IndiceTools.h"
#include "../c_math/Mandelbrot.h"
#include "../c_math/Julia.h"

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

MandelbrotJuliaMOO::MandelbrotJuliaMOO(unsigned int w, unsigned int h, int n):variateurT(IntervalI(25, 50), 1)
    {
    // Inputs
    this->n = n;
    this->w = w;
    this->h = h;
    this->domaineMathInit = DomaineMath(-1.3, -1.4, 1.3, 1.4);

    //Tools
    this->isEntrelacement = true;

    // OMP (facultatif)
    const int NB_THREADS = OmpTools::setAndGetNaturalGranularity();
    cout << "\n[MANDELBROTJULIA] nbThread = " << NB_THREADS << endl;
    }

MandelbrotJuliaMOO::~MandelbrotJuliaMOO(void)
    {
    // rien
    }

/*--------------------------------------*\
 |*		Override		*|
 \*-------------------------------------*/

/**
 * Override
 */
void MandelbrotJuliaMOO::process(uchar4* ptrTabPixels, int w, int h, const DomaineMath& domaineMath)
    {
    if (false)
	{
	entrelacementOMP(ptrTabPixels, w, h, domaineMath); // Plus lent
	}
    else
	{
	forAutoOMP(ptrTabPixels, w, h, domaineMath);  // Plus rapide
	}

    isEntrelacement = !isEntrelacement; // Pour tester que les deux implementations fonctionnent

    }

/**
 * Override
 */
void MandelbrotJuliaMOO::animationStep()
    {
    this->n = variateurT.varierAndGet();
    }

/*--------------*\
 |*	get	*|
 \*-------------*/

/**
 * Override
 */
float MandelbrotJuliaMOO::getAnimationPara()
    {
    return variateurT.get();
    }

/**
 * Override
 */
int MandelbrotJuliaMOO::getW()
    {
    return w;
    }

/**
 * Override
 */
int MandelbrotJuliaMOO::getH()
    {
    return h;
    }

/**
 * Override
 */
string MandelbrotJuliaMOO::getTitle()
    {
    return title;
    }

/**
 * Override
 */
DomaineMath* MandelbrotJuliaMOO::getDomaineMathInit(void)
    {
    return &domaineMathInit;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/**
 * Code naturel et direct OMP
 */
void MandelbrotJuliaMOO::forAutoOMP(uchar4* ptrTabPixels, int w, int h, const DomaineMath& domaineMath)
    {
    Mandelbrot fractal(n);

//    double c1 = -0.12;
//    double c2 = 0.85;
//    Julia fractal(n, c1, c2);
    MandelbrotJuliaMath MandelbrotJuliaMath(&fractal, n); // ici pour preparer cuda

#pragma omp parallel for
    for (int i = 0; i < h; i++)
	{
	for (int j = 0; j < w; j++)
	    {
	    //int s = i * W + j;
	    int s = IndiceTools::toS(w, i, j); // i[0,H[ j[0,W[  --> s[0,W*H[

	    workPixel(&ptrTabPixels[s], i, j, s, domaineMath, &MandelbrotJuliaMath);
	    }
	}
    }

/**
 * Code entrainement Cuda
 */
void MandelbrotJuliaMOO::entrelacementOMP(uchar4* ptrTabPixels, int w, int h, const DomaineMath& domaineMath)
    {
    Mandelbrot fractal(n);

//    double c1 = -0.12;
//    double c2 = 0.85;
//    Julia fractal(n, c1, c2);
    MandelbrotJuliaMath MandelbrotJuliaMath(&fractal, n); // ici pour preparer cuda

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

	    workPixel(&ptrTabPixels[s], i, j, s, domaineMath, &MandelbrotJuliaMath);

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
 * code commun �
 * 	entrelacementOMP
 * 	forAutoOMP
 */
void MandelbrotJuliaMOO::workPixel(uchar4* ptrColorIJ, int i, int j, int s, const DomaineMath& domaineMath, MandelbrotJuliaMath* ptrMandelbrotJuliaMath)
    {
    // (i,j) domaine ecran dans N2
    // (x,y) domaine math dans R2

    double x;
    double y;

    domaineMath.toXY(i, j, &x, &y); // fill (x,y) from (i,j)

    ptrMandelbrotJuliaMath->colorXY(ptrColorIJ, x, y, domaineMath); // in [01]
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

