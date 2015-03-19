#include <iostream>
#include <assert.h>

#include "DomaineMath.h"
#include "Mandelbrot.h"
#include "Device.h"
#include "MathTools.h"

using cpu::IntervalI;

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern __global__ void mandelbrot(uchar4* ptrDevPixels, int w, int h, DomaineMath ptrDomaineMathInit, int n, int nMax);

 /*-------------------------*\
 |*	Constructeur	    *|
 \*-------------------------*/

Mandelbrot::Mandelbrot(int w, int h, DomaineMath* domaineMath, int nMin, int nMax, float dt):
	variateurN(IntervalI(nMin, nMax), 1)
    {
    // Inputs
    this->w = w;
    this->h = h;
    this->nMin = nMin;
    this->n = nMin;
    this->nMax = nMax;
    this->ptrDomaineMathInit = domaineMath;

    // Tools
    this->dg = dim3(8, 8, 1);
    this->db = dim3(16, 16, 1);

    // Outputs
    this->title = "Mandelbrot";

    }

Mandelbrot::~Mandelbrot()
    {
    // rien
    }

/*-------------------------*\
 |*     Methode override    *|
 \*-------------------------*/

/**
 * Override
 * Call periodicly by the API
 */
void Mandelbrot::process(uchar4* ptrDevPixels, int w, int h, const DomaineMath& domaineMath)
    {
    mandelbrot<<<dg,db>>>(ptrDevPixels,w,h,domaineMath,n, nMin);
    }

void Mandelbrot::animationStep()
    {
    this->n = variateurN.varierAndGet();
    }

 /*--------------*\
 |* get override *|
 \*--------------*/
DomaineMath* Mandelbrot::getDomaineMathInit(void)
    {
    return ptrDomaineMathInit;
    }

/**
 * Override
 */
float Mandelbrot::getAnimationPara(void)
{
return variateurN.get();
}

float Mandelbrot::getT(void)
    {
    return n;
    }

string Mandelbrot::getTitle(void)
    {
    return title;
    }
int Mandelbrot::getW(void)
    {
    return w;
    }
int Mandelbrot::getH(void)
    {
    return h;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

