#include "MyGLUTWindow.h"

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
|*		Constructor		*|
 \*-------------------------------------*/

MyGLUTWindow::MyGLUTWindow(Displayable_A* ptrDisplayable, string title, int width, int height, int pxFrame, int pyFrame) :
	GLUTWindow(ptrDisplayable, title, width, height, pxFrame, pyFrame)
    {

    }

/*--------------------------------------*\
|*		Destructor		*|
 \*-------------------------------------*/

MyGLUTWindow::~MyGLUTWindow()
    {
    //Rien
    }

/*--------------------------------------*\
|*		Surcharge		*|
 \*-------------------------------------*/

/**
 * Override pour animation, appeler repaint
 */
void MyGLUTWindow::idleFunc()
    {
    repaint();
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

