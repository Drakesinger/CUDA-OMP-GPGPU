#ifndef GLUT_MULTI_THREAD_H_
#define GLUT_MULTI_THREAD_H_

#include "GLUTGraphWindow.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/


class GLUTMultithreadWindow: public GLUTGraphWindow
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:
	GLUTMultithreadWindow(Graph* ptrGraph, string title, int width, int height, int pxFrame = 0, int pyFrame = 0);
	virtual ~GLUTMultithreadWindow();

	/*--------------------------------------*\
	|*		Methode		*|
	 \*-------------------------------------*/

	/**
	 * Override
	 */
	virtual void idleFunc();

	/**
	 * Override
	 */
	virtual void postRendu();
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
