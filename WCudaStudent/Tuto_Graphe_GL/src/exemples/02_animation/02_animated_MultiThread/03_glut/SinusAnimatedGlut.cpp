#include "SinusAnimatedGlut.h"

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur		*|
 \*-------------------------------------*/

SinusAnimatedGlut::SinusAnimatedGlut(int w, int h, int px, int py)
    {
    this->ptrGraphe = new SinusGraphe();
    ptrGraphe->getSinusCurve()->setAnimationEnable(true); //  false par defaut

    this->ptrGLUTMultithreadWindow = new GLUTMultithreadWindow(ptrGraphe, "Sinus Animated Multi-Thread Analytique", w, h, px, py);
    }

SinusAnimatedGlut::~SinusAnimatedGlut()
    {
    delete ptrGLUTMultithreadWindow;
    delete ptrGraphe;
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

