#include <iostream>

#include "GLUTImageViewers.h"

#include "RipplingProvider.h"
#include "MandelbrotJuliaProvider.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported		*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int mainGL(void);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/


/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

int mainGL(void)
    {
    cout << "\n[OpenGL] mode" << endl;

    Image* ptrRippling = RipplingProvider::createGL();
    ImageFonctionel* ptrMandelbrot = MandelbrotJuliaProvider::createGL();

    // ImageViewer : (boolean,boolean) : (isAnimation,isSelectionEnable)
    // GLUTImageViewers rippplingViewer(ptrRippling, true, false, 0, 0);

    // Insert here other ImageViewer ...
    GLUTImageViewers MandelbrotViewer(ptrMandelbrot, true, true, 0, 0);

    GLUTImageViewers::runALL();  // Bloquant, Tant qu'une fenetre est ouverte

    // destruction
	{
	delete ptrRippling;

	ptrRippling = NULL;
	}

    return EXIT_SUCCESS;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

