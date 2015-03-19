#include <assert.h>

#include "Damier.h"
#include "Device.h"
#include "MathTools.h"

using cpu::IntervalF;


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

__global__ void damier(uchar4* ptrDevPixels, int w, int h, DomaineMath domaineMath, int n, float t);

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

/*-------------------------*\
 |*	Constructeur	    *|
 \*-------------------------*/

Damier::Damier(int w, int h, float dt, int n) :
	variateurAnimation(IntervalF(0, 2 * PI), dt)
    {
    // Inputs
    this->w = w;
    this->h = h;
    this->n = n;

    // Tools
    this->dg = dim3(8, 8, 1); // disons a optimiser
    this->db = dim3(16, 16, 1); // disons a optimiser
    this->t = 0;
    ptrDomaineMathInit=new DomaineMath(0,0,2*PI,2*PI);

    //Outputs
    this->title = "Damier_CUDA (Zoomable)";

    // Check:
    //print(dg, db);
    Device::assertDim(dg, db);
    }

Damier::~Damier()
    {
   delete ptrDomaineMathInit;
    }

/*-------------------------*\
 |*	Methode		    *|
 \*-------------------------*/

/**
 * Override
 * Call periodicly by the API
 */
void Damier::process(uchar4* ptrDevPixels, int w, int h, const DomaineMath& domaineMath)
    {
    damier<<<dg,db>>>(ptrDevPixels,w,h,domaineMath,n,t);
    }

/**
 * Override
 * Call periodicly by the API
 */
void Damier::animationStep()
    {
    this->t = variateurAnimation.varierAndGet(); // in [0,2pi]
    }


/*--------------*\
 |*	get	 *|
 \*--------------*/

/**
 * Override
 */
DomaineMath* Damier::getDomaineMathInit(void)
    {
    return ptrDomaineMathInit;
    }

/**
 * Override
 */
float Damier::getAnimationPara(void)
    {
    return t;
    }

/**
 * Override
 */
int Damier::getW(void)
    {
    return w;
    }

/**
 * Override
 */
int Damier::getH(void)
    {
    return h;
    }

/**
 * Override
 */
string Damier::getTitle(void)
    {
    return title;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

