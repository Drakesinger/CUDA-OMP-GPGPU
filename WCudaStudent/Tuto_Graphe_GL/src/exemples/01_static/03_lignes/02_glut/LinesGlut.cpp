#include "LinesGlut.h"

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur		*|
 \*-------------------------------------*/

LinesGlut::LinesGlut(int w, int h, int px, int py)
    {
    this->ptrGraphe=new LinesGraphe();
    this->ptrGLUTGraphWindow = new GLUTGraphWindow(ptrGraphe, "Lines", w, h, px, py);
    }

LinesGlut::~LinesGlut()
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

