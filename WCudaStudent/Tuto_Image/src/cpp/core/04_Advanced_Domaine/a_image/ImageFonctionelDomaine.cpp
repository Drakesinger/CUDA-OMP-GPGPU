#include "ImageFonctionelDomaine.h"
/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

ImageFonctionelDomaine::ImageFonctionelDomaine(AnimableFonctionel_I* ptrAnimable) :
	ImageFonctionel(ptrAnimable)
    {

    controle();
    }

ImageFonctionelDomaine::~ImageFonctionelDomaine()
    {
    getDomaineHistory()->removeOnDomaineChangedListener(ptrDomaineListener);
    delete ptrDomaineListener;
    delete ptrKeyListener;
    }

void ImageFonctionelDomaine::paintPrimitives(Graphic2D& graphic2D)
    {
    ImageFonctionel::paintPrimitives(graphic2D);
    float r = 0;
    float g = 0;
    float b = 0;
    graphic2D.setColorRGB(r, g, b);
    graphic2D.setFont(TIMES_ROMAN_24);

    int fontHeight = graphic2D.getFont()->height;
    int y0 = 100;
    // Key '1'
	{
	string message = "1 go to initial Domaine";
	graphic2D.drawText(0, y0 + fontHeight, message);
	}

    // Key '2'
	{
	string message = "2 go to previous Domaine";
	graphic2D.drawText(0, y0 + 2 * fontHeight, message);
	}

    // Key '3'
	{
	string message = "3 set predefined domaine";
	graphic2D.drawText(0, y0 + 3 * fontHeight, message);
	}
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

void ImageFonctionelDomaine::controle()
    {
    ptrKeyListener = new DomaineKeyListener(this);
    ptrDomaineListener= new DomaineListener();

    setKeyListener(ptrKeyListener);
    getDomaineHistory()->addOnDomaineChangedListener(ptrDomaineListener);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

