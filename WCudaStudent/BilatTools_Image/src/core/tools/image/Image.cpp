#include <iostream>
#include "Image.h"
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

Image::Image(Animable_I* ptrAnimable) :
	Image_A(ptrAnimable->getW(), ptrAnimable->getH())
    {
    this->ptrAnimable = ptrAnimable;
    }

Image::~Image(void)
    {
   delete ptrAnimable;// TODO discutable
    }

/*--------------------------------------*\
 |*		Override		*|
 \*-------------------------------------*/

/**
 * Override, call periodicly by the api
 */
void Image::fillImageGL(uchar4* ptrTabPixels, int w, int h)
    {
    ptrAnimable->process(ptrTabPixels, w, h);
    }

/**
 * Override, call periodicly by the api
 */
void Image::animationStep(bool& isNeedUpdateView)
    {
    ptrAnimable->animationStep();
    }

/**
 * Override, call periodicly by the api
 */
void Image::paintPrimitives(Graphic2D& graphic2D)
    {
    graphic2D.setFont(TIMES_ROMAN_24);

    float r = 0;
    float g = 1;
    float b = 0;

    graphic2D.setColorRGB(r, g, b);

    // Top : Para Animation
	{
	float t = ptrAnimable->getAnimationPara();

	string message = "t = " + StringTools::toString(t);

	graphic2D.drawTitleTop(message);
	}

    // Bottom : Title
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
