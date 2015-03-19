#include <iostream>
#include <assert.h>
#include <math.h>

#include "MathTools.h"
#include "WarmupImage.h"
#include "StringTools.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern void launchKernelWarmup(uchar4* ptrDevPixels, int w, int h, float t);

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
    // Tools
    this->ptrWarmup = new Warmup(w, h, t);
    }

WarmupImage::~WarmupImage(void)
    {
    delete ptrWarmup;
    }

/*--------------------------------------*\
 |*		Override		*|
 \*-------------------------------------*/

/**
 * Override
 * Call automaticly by the api
 */
void WarmupImage::animationStep(bool& isNeedUpdateView)
    {
    ptrWarmup->animationStep();
   // isNeedUpdateView = true; // true par default
    }

/**
 * Override
 * Call automaticly by the api
 */
void WarmupImage::fillImageGL(uchar4* ptrDevPixels, int w, int h)
    {
    ptrWarmup->process(ptrDevPixels,w,h);
    }

/**
 * Override
 * Call automaticly by the api
 */
void WarmupImage::paintPrimitives(Graphic2D& graphic2D)
    {
    graphic2D.setFont(TIMES_ROMAN_24);

    float r = 1;
    float g = 0;
    float b = 0;

    graphic2D.setColorRGB(r, g, b);

    // top
	{
	float t=ptrWarmup->getAnimationPara();

	string message = "t = " + StringTools::toString(t);
	graphic2D.drawTitleTop(message);
	}

    // bottom
	{
	string title=ptrWarmup->getTitle();

	graphic2D.drawTitleBottom(title);
	}
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
