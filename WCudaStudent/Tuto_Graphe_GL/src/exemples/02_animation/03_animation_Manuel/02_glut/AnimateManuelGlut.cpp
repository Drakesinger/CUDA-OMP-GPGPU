#include "AnimateManuelGlut.h"

#include <omp.h>

#include "GLUTWindowManagers.h"
#include "BoostTools.h"

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur		*|
 \*-------------------------------------*/

AnimateManuelGlut::AnimateManuelGlut(int w, int h, int px, int py)
    {
    createGraph();
    createGLGraph();

    createGLUTWindow(w,h,px,py);
    }

AnimateManuelGlut::~AnimateManuelGlut()
    {
    delete ptrGlutWindow;
    delete ptrSinusGraphe;
    delete ptrGlGraph;
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

/*-----------------*\
 |*  public	   *|
 \*----------------*/

void AnimateManuelGlut::run()
    {
    // On utilise un pool de thread OMP avec 2 threads:
    //		main-Thread
    //		thread2
#pragma omp parallel num_threads(2)
	{

	// On utilise le thread master pour effecteure la glutMainLoop!
	// Il s'agit d'une contrainte glut. glut est monothread est le glut-thread doit être le main-thread.
#pragma omp master
	    {
	    GLUTWindowManagers::getInstance()->runALL();
	    }

	//Le deuxière thread du la section parallele s'occupe de faire l'animation!
	animer();

	}	 // bloquant tant que la fentre pas ferme

    }

/*-----------------*\
 |*  private	   *|
 \*----------------*/

void AnimateManuelGlut::createGraph()
    {
    this->ptrSinusGraphe = new SinusGraphe();
    }

void AnimateManuelGlut::createGLGraph()
    {
    this->ptrGlGraph = new GLGraph(ptrSinusGraphe);
    }

void AnimateManuelGlut::createGLUTWindow(int w, int h, int px, int py)
    {
    this->ptrGlutWindow = new GLUTWindow(ptrGlGraph, "Animation manuel for Advanced User", w, h, px, py);
    }

/**
 * L'animation est dans un thread séparée
 */
void AnimateManuelGlut::animer()
    {
    const long DELAY_MS_1 = 1;

    this->ptrSinusGraphe->getSinusCurve()->setAnimationEnable(true);

    while (!ptrGlutWindow->isDestroyed())
	{
	ptrSinusGraphe->animationStep();

	//ptrGraph->update();
	ptrGlutWindow->repaint();

	BoostTools::sleep(DELAY_MS_1); // max 1000 fps
	}
    }



/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

