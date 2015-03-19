#include "NuagePointGlut.h"


/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur		*|
 \*-------------------------------------*/

NuagePointGlut::NuagePointGlut(int w, int h, int px, int py)
    {
    this->ptrGraphe=new NuagesPointsGraphe();
    this->ptrGLUTGraphWindow = new GLUTGraphWindow(ptrGraphe, "Nuage Point", w, h, px, py);
    }

NuagePointGlut::~NuagePointGlut()
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

