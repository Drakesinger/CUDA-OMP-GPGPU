#include "GLUTMultithreadWindow.h"
#include "BoostTools.h"


/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur			*|
 \*-------------------------------------*/

GLUTMultithreadWindow::GLUTMultithreadWindow(Graph* ptrGraph, string title, int width, int height, int pxFrame, int pyFrame) :
	GLUTGraphWindow(ptrGraph, title, width, height, pxFrame, pyFrame)
    {
    // Rien
    }

GLUTMultithreadWindow::~GLUTMultithreadWindow()
    {
    // Rien
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

/**
 * Override
 */
void GLUTMultithreadWindow::idleFunc()
    {
    //Rien, l'animation par defaut serait fait ici, voir premier example
    // Note : on pourrait cumuler les deux types d'animation.
    }

/**
 * Override
 * La methode postRendu est appelée 1 fois dans un thread spécifique destinée à cette unique fenêtre.
 * Ce thread est differentz du glut-thread (main-thread)
 */
void GLUTMultithreadWindow::postRendu()
    {
    const long DELAY_MS=10;

    while (!isDestroyed())
	{
	if (getGraph()->animationStep())
	    {
	    repaint();
	    }

	BoostTools::sleep(DELAY_MS);
	}
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

