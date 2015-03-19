#include <iostream>
#include <assert.h>

#include "Advanced.h"
#include "Device.h"
#include "MathTools.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern __global__ void advanced(uchar4* ptrDevPixels,int w, int h,DomaineMath domaineMath,float t);

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

Advanced::Advanced(int w, int h, float dt)
    {
    // Inputs
    this->w = w;
    this->h = h;
    this->dt=dt;

    // Tools
    this->dg = dim3(8, 8, 1); // disons a optimiser
    this->db = dim3(16, 16, 1); // disons a optimiser
    this->t = 0;
    ptrDomaineMathInit = new DomaineMath(0, 0, 10, 10);

    //Outputs
    this->title = "Advanced_Cuda";

    // Check:
    //print(dg, db);
    Device::assertDim(dg, db);
    }

Advanced::~Advanced()
    {
    // rien
    }

/*-------------------------*\
 |*	Methode		    *|
 \*-------------------------*/

/**
 * Override
 * Call periodicly by the API
 */
void Advanced::process(uchar4* ptrDevPixels, int w, int h, const DomaineMath& domaineMath)
    {
    advanced<<<dg,db>>>(ptrDevPixels,w,h,domaineMath,t);
    }

/**
 * Override
 * Call periodicly by the API
 */
void Advanced::animationStep()
    {
    t+=dt;
    }

/*--------------*\
 |*	get	 *|
 \*--------------*/


/**
 * Override
 */
DomaineMath* Advanced::getDomaineMathInit(void)
    {
    return ptrDomaineMathInit;
    }

/**
 * Override
 */
float Advanced::getAnimationPara(void)
    {
    return t;
    }

/**
 * Override
 */
int Advanced::getW(void)
    {
    return w;
    }

/**
 * Override
 */
int Advanced::getH(void)
    {
    return h;
    }

/**
 * Override
 */
string Advanced::getTitle(void)
    {
    return title;
    }


/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

