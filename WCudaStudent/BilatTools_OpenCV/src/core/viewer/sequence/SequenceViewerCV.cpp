#include "SequenceViewerCV.h"
#include "ImageViewerCV.h"
#include <iostream>
#include <omp.h>

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

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

SequenceVieverCV::SequenceVieverCV(Capture_A* ptrCaptureur)
    {
    cout<<"[SequenceViever] : SequenceViever"<<endl;
    this->ptrCaptureur = ptrCaptureur;
    this->isStart = false;
    }

SequenceVieverCV::~SequenceVieverCV(void)
    {
    // rien
    }

void SequenceVieverCV::run()
    {
    cout<<"[SequenceViever] : run"<<endl;

    if (!isStart)
	{
	isStart = true;

	Mat image = ptrCaptureur->capturer();
	ptrCaptureur->printInfo();

	string titleFrame = ptrCaptureur->getTitle() + "[q to quit]";
	ImageVieverCV imageViever(titleFrame);

	Chronos chrono;
	char key = 'a'; //disons
	while (key != 'q')
	    {
	    imageViever.show(&image);
	    image = ptrCaptureur->capturer();

	    int timetoWaitYetMS = timeToWaitMS(&chrono); // FIXME
	    key = cvWaitKey(max(1, timetoWaitYetMS)); // attention 1 min, pour respecter cadence original

	    if (ptrCaptureur->nbCapture() % 60 == 0) //disons
		{
		cout << "[SequenceViewer] : fps = " << ptrCaptureur->fpsCapture() << endl;
		// ptrCaptureur->printInfo();
		}
	    }

	isStart = false;
	}
    }

int SequenceVieverCV::fps()
    {
    return ptrCaptureur->fpsCapture();
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

int SequenceVieverCV::timeToWaitMS(Chronos* ptrChrono) // TODO BUG play trop vite why?
    {
    double timeElapseS = ptrChrono->stop();
    ptrChrono->start();

    int timeElapseMS = (int) (timeElapseS * 1000);
    int timeToWaitTheoriqueMS = ptrCaptureur->dtOriginalMS();

    int timetoWaitYetMS = timeToWaitTheoriqueMS - timeElapseMS;
    timetoWaitYetMS = max(0, timetoWaitYetMS); // 0 si negatif

    // debug
//	{
//	cout << endl;
//	cout << "timeToWaitTheorique (MS)   = " << timeToWaitTheoriqueMS << endl;
//	cout << "timeElapse (MS)            = " << timeElapseMS << endl;
//	cout << "timetoWaitYet (MS)         = " << timetoWaitYetMS << endl;
//	cout << endl;
//	}

    return timetoWaitYetMS;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

