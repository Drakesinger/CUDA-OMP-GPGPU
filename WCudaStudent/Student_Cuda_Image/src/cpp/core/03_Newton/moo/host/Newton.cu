#include <iostream>
#include <assert.h>

#include "DomaineMath.h"
#include "Newton.h"
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

extern __global__ void newton(uchar4* ptrDevPixels, int w, int h, DomaineMath ptrDomaineMathInit, int n, float epsilon);

 /*-------------------------*\
 |*	Constructeur	    *|
 \*-------------------------*/

Newton::Newton(int w, int h, DomaineMath* domaineMath, int nMin, int nMax, float dt, float epsilon):
	variateurN(IntervalI(nMin, nMax), 1)
    {
    // Inputs
    this->w = w;
    this->h = h;
    this->nMin = nMin;
    this->n = nMin;
    this->nMax = nMax;
    this->ptrDomaineMathInit = domaineMath;
    this->epsilon = epsilon;

    // Tools
    this->dg = dim3(8, 8, 1);
    this->db = dim3(16, 16, 1);

    // Outputs
    this->title = "Newton";

    }

Newton::~Newton()
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
void Newton::process(uchar4* ptrDevPixels, int w, int h, const DomaineMath& domaineMath)
    {
    newton<<<dg,db>>>(ptrDevPixels,w,h,domaineMath,n, epsilon);
    }

void Newton::animationStep()
    {
    this->n = variateurN.varierAndGet();
    }

 /*--------------*\
 |* get override *|
 \*--------------*/
DomaineMath* Newton::getDomaineMathInit(void)
    {
    return ptrDomaineMathInit;
    }

/**
 * Override
 */
float Newton::getAnimationPara(void)
{
return variateurN.get();
}

float Newton::getT(void)
    {
    return n;
    }

string Newton::getTitle(void)
    {
    return title;
    }
int Newton::getW(void)
    {
    return w;
    }
int Newton::getH(void)
    {
    return h;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

