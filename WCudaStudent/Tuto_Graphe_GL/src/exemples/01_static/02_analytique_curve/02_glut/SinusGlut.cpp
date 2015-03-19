#include "SinusGlut.h"

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur		*|
 \*-------------------------------------*/

SinusGlut::SinusGlut(int w, int h, int px, int py)
    {
    this->ptrGraphe = new SinusGraphe();
    this->ptrGLUTGraphWindow = new GLUTGraphWindow(ptrGraphe, "Sinus Analytique", w, h, px, py);
    }

SinusGlut::~SinusGlut()
    {
    delete ptrGLUTGraphWindow;
    delete ptrGraphe;
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

/*-------------*\
 |*	get	*|
 \*------------*/

SinusGraphe* SinusGlut::getSinusGraphe()
    {
    return ptrGraphe;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

