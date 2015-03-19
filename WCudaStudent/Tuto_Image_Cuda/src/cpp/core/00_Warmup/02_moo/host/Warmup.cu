#include <iostream>
#include <assert.h>

#include "Warmup.h"
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

extern __global__ void warmup(uchar4* ptrDevPixels,int w, int h,float t);

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*-------------------------*\
 |*	Constructeur	    *|
 \*-------------------------*/

Warmup::Warmup(int w, int h,float dt)
    {
    // Inputs
    this->w = w;
    this->h = h;
    this->dt=dt;

    // Tools
    this->dg = dim3(8, 8, 1); // disons a optimiser
    this->db = dim3(16, 16, 1); // disons a optimiser
    this->t=0;

    //Outputs
    this->title="Warmup_Cuda";

    // Check:
    //print(dg, db);
    Device::assertDim(dg, db);

    cout << endl<<"[Warmup]  dt =" << dt;
    }

Warmup::~Warmup()
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
void Warmup::process(uchar4* ptrDevPixels, int w, int h)
    {
    warmup<<<dg,db>>>(ptrDevPixels,w,h,t);
    }

/**
 * Override
 * Call periodicly by the API
 */
void Warmup::animationStep()
    {
    t+=dt;
    }

/*--------------*\
 |*	get	 *|
 \*--------------*/

/**
 * Override
 */
float Warmup::getAnimationPara(void)
    {
    return t;
    }

/**
 * Override
 */
int Warmup::getW(void)
    {
    return w;
    }

/**
 * Override
 */
int Warmup::getH(void)
    {
    return  h;
    }

/**
 * Override
 */
string Warmup::getTitle(void)
    {
    return title;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

