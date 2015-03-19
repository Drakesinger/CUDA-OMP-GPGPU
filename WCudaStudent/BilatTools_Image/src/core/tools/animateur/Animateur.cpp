#include <iostream>
#include <math.h>

#include "Animateur.h"

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

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur		*|
 \*-------------------------------------*/

Animateur::Animateur(Animable_I* ptrAnimable, int nbIteration)
    {
    // Input
    this->nbIteration = nbIteration;
    this->ptrAnimable = ptrAnimable;

    // Outputs
    this->fps = -1;
    this->timeElapseS = -1;

    // tools
    this->ptrChrono = new Chronos();
    }

Animateur::~Animateur()
    {
    delete ptrChrono;
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

int Animateur::run()
    {
    start();
    printStat();

    return fps;
    }


void Animateur::printStat()
    {
    cout << endl;
    cout << "[" << ptrAnimable->getTitle() << "]" << endl;
    cout << "#(w,h)      : (" << ptrAnimable->getW() << "," << ptrAnimable->getH() << ")" << endl;
    cout << "#Iteration  : " << nbIteration << endl;
    cout << "#secondes   : " << timeElapseS << " (s)" << endl;
    cout << "#fps        : " << fps << endl;
    }

/*--------------*\
 |*	get	*|
 \*-------------*/

int Animateur::getFps(void)
    {
    return fps;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

int Animateur::start()
    {
    const int W = ptrAnimable->getW();
    const int H = ptrAnimable->getH();
    string title = ptrAnimable->getTitle();

    cout << endl << "[" << title << "] : fps : processing ..." << endl;

    uchar4* ptrImage = new uchar4[W * H];

    ptrChrono->start();
    for (int i = 1; i <= nbIteration; i++)
	{
	ptrAnimable->process(ptrImage, W, H);
	ptrAnimable->animationStep();
	}
    ptrChrono->stop();

    fpsProcess();
    // cout << "[" << title << "] : fps = " << fps << endl;

    delete[] ptrImage;

    return fps;
    }

void Animateur::fpsProcess()
    {
    this->timeElapseS = ptrChrono->getDeltaTime();

    // cout<<timeElapseS<<endl;

    this->fps = ceil(nbIteration / timeElapseS);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

