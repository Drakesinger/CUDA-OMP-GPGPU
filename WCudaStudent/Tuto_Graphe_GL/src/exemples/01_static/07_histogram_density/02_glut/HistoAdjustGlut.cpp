#include "HistoAdjustGlut.h"

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur		*|
 \*-------------------------------------*/

HistoAdjustGlut::HistoAdjustGlut(int w, int h, int px, int py)
    {
    this->ptrGraphe = new HistoAdjustGraphe();
    this->ptrGLUTGraphWindow = new GLUTGraphWindow(ptrGraphe, "Histo Adjust", w, h, px, py);
    }

HistoAdjustGlut::~HistoAdjustGlut()
    {
    delete ptrGLUTGraphWindow;
    delete ptrGraphe;
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

