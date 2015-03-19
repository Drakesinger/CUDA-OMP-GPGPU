#include <iostream>

#include "AdvancedImage.h"

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

AdvancedImage::AdvancedImage(Animable_I* ptrAnimable) :
	Image_A(ptrAnimable->getW(), ptrAnimable->getH())
    {
    // Inputs
    this->ptrAnimable = ptrAnimable;

    // Tools
    this->ptrDrawer2D = new Drawer2D(ptrAnimable->getW(), ptrAnimable->getH());

    control();
    }

AdvancedImage::~AdvancedImage(void)
    {
    delete ptrKeyListener;
    delete ptrMouseListener;
    delete ptrDrawer2D;
    }

/*--------------------------------------*\
 |*		Override		*|
 \*-------------------------------------*/

/**
 * Override
 * call periodicly by the api
 */
void AdvancedImage::fillImageGL(uchar4* ptrTabPixels, int w, int h)
    {
    ptrAnimable->process(ptrTabPixels, w, h);
    }

/**
 * Override
 * call periodicly by the api
 */
void AdvancedImage::animationStep(bool& isNeedUpdateView)
    {
    ptrAnimable->animationStep();
    }

/**
 * Override
 * call periodicly by the api
 */
void AdvancedImage::paintPrimitives(Graphic2D& graphic2D)
    {
    graphic2D.setFont(TIMES_ROMAN_24);

    float r = 1;
    float g = 0;
    float b = 0;
    graphic2D.setColorRGB(r, g, b);

    // Top
	{
	float t = ptrAnimable->getAnimationPara();

	string title = ptrAnimable->getTitle();

	graphic2D.drawTitleBottom(title);
	}

    // Bottom
	{
	graphic2D.drawTitleTop("Advanced : Click on the windows, and look message in the console");
	}

    // Drawer2D
	{
	ptrDrawer2D->drawObjet(graphic2D);
	ptrDrawer2D->drawNonObjet(graphic2D);
	}
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

void AdvancedImage::control(void)
    {
    this->ptrKeyListener = new SimpleKeyListener();
    this->ptrMouseListener = new SimpleMouseListener();

    setKeyListener(ptrKeyListener);
    setMouseListener(ptrMouseListener);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

