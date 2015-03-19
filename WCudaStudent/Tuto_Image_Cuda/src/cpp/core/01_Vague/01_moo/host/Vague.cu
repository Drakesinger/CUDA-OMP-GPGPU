#include <iostream>
#include <assert.h>

#include "Vague.h"
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

extern __global__ void vague(uchar4* ptrDevPixels,int w, int h,float t);

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

Vague::Vague(int w, int h,float dt)
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
    this->title="Vague_Cuda";

    // Check:
    //print(dg, db);
    Device::assertDim(dg, db);

    cout << endl<<"[Vague]  dt =" << dt;
    }

Vague::~Vague()
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
void Vague::process(uchar4* ptrDevPixels, int w, int h)
    {
    vague<<<dg,db>>>(ptrDevPixels,w,h,t);
    }

/**
 * Override
 * Call periodicly by the API
 */
void Vague::animationStep()
    {
    t+=dt;
    }

/*--------------*\
 |*	get	 *|
 \*--------------*/

/**
 * Override
 */
float Vague::getAnimationPara(void)
    {
    return t;
    }

/**
 * Override
 */
int Vague::getW(void)
    {
    return w;
    }

/**
 * Override
 */
int Vague::getH(void)
    {
    return  h;
    }

/**
 * Override
 */
string Vague::getTitle(void)
    {
    return title;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

