#ifndef MYGLUTWINDOW_H_
#define MYGLUTWINDOW_H_

#include "GLUTWindow.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class MyGLUTWindow: public GLUTWindow
    {
    public:

	 /*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

	MyGLUTWindow(Displayable_A* ptrDisplayable, string title, int width, int height, int pxFrame = 0, int pyFrame = 0);

	/*--------------------------------------*\
	 |*		Destructor		*|
	 \*-------------------------------------*/

	virtual ~MyGLUTWindow();

	/*--------------------------------------*\
	 |*		Surcharge		*|
	 \*-------------------------------------*/

	/**
	 * Override pour animation, appeler repaint
	 */
	virtual void idleFunc();
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
