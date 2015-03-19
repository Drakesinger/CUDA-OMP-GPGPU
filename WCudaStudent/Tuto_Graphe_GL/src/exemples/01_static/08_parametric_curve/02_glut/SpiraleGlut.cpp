#include "SpiraleGlut.h"


/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur		*|
 \*-------------------------------------*/

SpiraleGlut::SpiraleGlut(int w, int h, int px, int py)
    {
    this->ptrGraphe=new SpiraleGraphe();
    this->ptrGLUTGraphWindow = new GLUTGraphWindow(ptrGraphe, "Spirale", w, h, px, py);
    }

SpiraleGlut::~SpiraleGlut()
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

