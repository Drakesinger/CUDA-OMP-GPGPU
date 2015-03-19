#include <iostream>

#include "cudaTools.h"
#include "Device.h"
#include "MathTools.h"

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

    //Tools
    this->ptrChrono = new Chronos();
    }

Animateur::~Animateur()
    {
    delete ptrChrono;
    }

/*--------------------------------------*\
 |*		Public			*|
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

    size_t size = W * H * sizeof(uchar4);
    uchar4* ptrDevImage;
    HANDLE_ERROR(cudaMalloc((void**) &ptrDevImage, size));
    HANDLE_ERROR(cudaMemset(ptrDevImage, 0, size));

    const char* messageError = ptrAnimable->getTitle().c_str();

    ptrChrono->start();
    for (int i = 1; i <= nbIteration; i++)
	{
	ptrAnimable->process(ptrDevImage, W, H);

	Device::checkKernelError(messageError);
	Device::synchronize(); // Important!

	ptrAnimable->animationStep();

	i++;
	}
    ptrChrono->stop();

    fpsProcess();

    HANDLE_ERROR(cudaFree(ptrDevImage));

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

