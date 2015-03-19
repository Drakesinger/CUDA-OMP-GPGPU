#include <iostream>
#include <assert.h>
#include <math.h>

#include "ImageFonctionel.h"
#include "StringTools.h"
#include "MathTools.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

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

ImageFonctionel::ImageFonctionel(AnimableFonctionel_I* ptrAnimable, ColorRGB_01* ptrColorTitreRGB) :
	ImageFonctionel_A(ptrAnimable->getW(), ptrAnimable->getH(), *ptrAnimable->getDomaineMathInit())
    {
    this->ptrAnimable = ptrAnimable;
    this->ptrColorTitreRGB = ptrColorTitreRGB;

    setEnableDomaineOverlay(true);
    }

ImageFonctionel::~ImageFonctionel(void)
    {
    delete ptrAnimable;
    }

/**
 * Override
 */
void ImageFonctionel::animationStep(bool& isNeedUpdateView)
    {
    // cout << "[CBI] : Image : animationStep" <<endl;

    ptrAnimable->animationStep();
    isNeedUpdateView = true; // true par default
    }

/**
 * Override
 */
void ImageFonctionel::fillImageGL(uchar4* ptrDevImageGL, int w, int h, const DomaineMath& domaineMath) // override
    {
    // cout << "[CBI] : Image : fillImageGL" <<endl;

    ptrAnimable->process(ptrDevImageGL, w,h,domaineMath);
    }

/**
 * Override
 */
void ImageFonctionel::paintPrimitives(Graphic2D& graphic2D)
    {
    graphic2D.setFont(TIMES_ROMAN_24);

    float r = ptrColorTitreRGB->r;
    float g = ptrColorTitreRGB->g;
    float b = ptrColorTitreRGB->b;
    graphic2D.setColorRGB(r, g, b);

    // top
	{
	float t = ptrAnimable->getAnimationPara();
	string message = "t = " + StringTools::toString(t);
	graphic2D.drawTitleTop(message);
	}

    // bottom
	{
	string title = ptrAnimable->getTitle();
	graphic2D.drawTitleBottom(title);
	}
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
