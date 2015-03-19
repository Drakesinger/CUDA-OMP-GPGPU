#include <iostream>
#include <assert.h>
#include <omp.h>
#include <math.h>

#include "WarmupImage.h"
#include "MathTools.h"
#include "StringTools.h"
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

WarmupImage::WarmupImage(unsigned int w, unsigned int h, float dt) :
	Image_A(w, h)
    {
    // Inputs
    this->title="Warmup_MOO";

    // Tools
    this->ptrWarmupMOO=new WarmupMOO(w,h,dt);
    }

WarmupImage::~WarmupImage(void)
    {
    delete ptrWarmupMOO;
    }

/*--------------------------------------*\
 |*		Override		*|
 \*-------------------------------------*/

/**
 * Override : call periodicly by the api
 */
void WarmupImage::fillImageGL(uchar4* ptrTabPixels, int w, int h)
    {
    ptrWarmupMOO->process(ptrTabPixels,w,h);
    }

/**
 * Override : call periodicly by the api
 */
void WarmupImage::animationStep(bool& isNeedUpdateView)
    {
    //isNeedUpdateView = true; // true par default
    ptrWarmupMOO->animationStep();
    }

/**
 * Override call periodicly by the api
 */
void WarmupImage::paintPrimitives(Graphic2D& graphic2D)
    {
    graphic2D.setFont(TIMES_ROMAN_24);

    float r = 1;
    float g = 0;
    float b = 0;
    graphic2D.setColorRGB(r, g, b);

    // Top
	{
	float t=ptrWarmupMOO->getAnimationPara();

	string message = "t= " + StringTools::toString(t);
	graphic2D.drawTitleTop(message);
	}

    // Bottom
	{
	graphic2D.drawTitleBottom(title);
	}
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/



/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

