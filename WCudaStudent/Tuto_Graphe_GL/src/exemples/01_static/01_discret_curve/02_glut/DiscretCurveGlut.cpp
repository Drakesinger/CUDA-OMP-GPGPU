#include "DiscretCurveGlut.h"


/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur		*|
 \*-------------------------------------*/

DiscretCurveGlut::DiscretCurveGlut(int w, int h, int px, int py)
    {
    this->ptrGraphe=new DiscretCurveGraph();
    this->ptrGLUTGraphWindow = new GLUTGraphWindow(ptrGraphe, "Discret Curve tabPoints", w, h, px, py);
    }

DiscretCurveGlut::~DiscretCurveGlut()
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

