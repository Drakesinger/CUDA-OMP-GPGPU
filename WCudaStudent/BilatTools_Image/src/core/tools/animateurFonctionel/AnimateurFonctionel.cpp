#include <iostream>
#include <math.h>

#include "AnimateurFonctionel.h"

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
 |*		Public			*|
 \*-------------------------------------*/

AnimateurFonctionel::AnimateurFonctionel(AnimableFonctionel_I* ptrAnimable, int nbIteration)
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

AnimateurFonctionel::~AnimateurFonctionel()
    {
    delete ptrChrono;
    }

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int AnimateurFonctionel::run()
    {
    start();
    printStat();

    return fps;
    }

int AnimateurFonctionel::getFps(void)
    {
    return fps;
    }

void AnimateurFonctionel::printStat()
    {
    cout << endl;
    cout << "[" << ptrAnimable->getTitle() << "]" << endl;
    cout << "#(w,h)      : (" << ptrAnimable->getW() << "," << ptrAnimable->getH() << ")" << endl;
    cout << "#Iteration  : " << nbIteration << endl;
    cout << "#secondes   : " << timeElapseS << " (s)" << endl;
    cout << "#fps        : " << fps << endl;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

int AnimateurFonctionel::start()
    {
    const int W = ptrAnimable->getW();
    const int H = ptrAnimable->getH();
    string title = ptrAnimable->getTitle();

    cout << endl << "[" << title << "] : fps : processing ..." << endl;

    uchar4* ptrImage = new uchar4[W * H];
    DomaineMath* domaineMath = ptrAnimable->getDomaineMathInit();

    ptrChrono->start();
    for (int i = 1; i <= nbIteration; i++)
	{
	ptrAnimable->process(ptrImage, W, H,*domaineMath);
	ptrAnimable->animationStep();
	}
    ptrChrono->stop();

    fpsProcess();
    //cout << "[" << title << "] : fps = " << fps << endl;

    delete[] ptrImage;

    return fps;
    }

void AnimateurFonctionel::fpsProcess()
    {
    this->timeElapseS = ptrChrono->getDeltaTime();

    // cout<<timeElapseS<<endl;

    this->fps=ceil(nbIteration / timeElapseS);
    }



/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

