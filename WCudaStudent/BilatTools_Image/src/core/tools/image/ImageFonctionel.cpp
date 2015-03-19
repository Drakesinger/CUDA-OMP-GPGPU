#include <iostream>
#include "ImageFonctionel.h"
#include "StringTools.h"

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
 |*		Constructeur		*|
 \*-------------------------------------*/

ImageFonctionel::ImageFonctionel(AnimableFonctionel_I* ptrAnimable) :
	ImageFonctionel_A(ptrAnimable->getW(), ptrAnimable->getH(), *ptrAnimable->getDomaineMathInit())
    {
    this->ptrAnimable = ptrAnimable;
    setEnableDomaineOverlay(true);
    }

ImageFonctionel::~ImageFonctionel(void)
    {
    delete ptrAnimable;// TODO discutable
    }

/*--------------------------------------*\
 |*		Override		*|
 \*-------------------------------------*/

/**
 * Override, call periodicly by the api
 */
void ImageFonctionel::fillImageGL(uchar4* ptrTabPixels, int w, int h, const DomaineMath& domaineMath)
    {
    ptrAnimable->process(ptrTabPixels, w, h, domaineMath);
    }

/**
 * Override, call periodicly by the api
 */
void ImageFonctionel::animationStep(bool& isNeedUpdateView)
    {
    ptrAnimable->animationStep();
    }

/**
 * Override, call periodicly by the api
 */
void ImageFonctionel::paintPrimitives(Graphic2D& graphic2D)
    {
    graphic2D.setFont(TIMES_ROMAN_24);

    float r = 0;
    float g = 1;
    float b = 0;

    graphic2D.setColorRGB(r, g, b);

    // TOP : Para Animation
	{
	float t = ptrAnimable->getAnimationPara();

	string message = "t = " + StringTools::toString(t);

	graphic2D.drawTitleTop(message);
	}

    // BOTTOM : Title
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
