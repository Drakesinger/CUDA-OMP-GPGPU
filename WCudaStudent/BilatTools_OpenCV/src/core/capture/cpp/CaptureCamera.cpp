#include <iostream>
#include "CaptureCamera.h"

using std::cerr;
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

/*------------------*\
 |*  Constructeur     *|
 \*-----------------*/

/**
 * see doc of Capture_A constructor for cuda use (ptrHostMemory)
 */
CaptureCamera::CaptureCamera(int idCamera, const string& title, int wAsk, int hAsk, uchar4* ptrHostMemory) :
	Capture_A(createStream(idCamera, wAsk, hAsk), title, ptrHostMemory)

    {
    this->idCamera = idCamera;
    this->wAsk = wAsk;
    this->hAsk = hAsk;
    }

CaptureCamera::~CaptureCamera(void)
    {
    // rien
    //  delete ptrCaptureStream; in constructor
    }

/*------------------*\
 |*	Methode	     *|
 \*-----------------*/

void CaptureCamera::printInfo(void)
    {
    Capture_A::printInfo();

    cout << "\t(w,h) asked    = (" << wAsk << "," << hAsk << ") " << endl;

    cout << endl;
    }

void CaptureCamera::readStream(VideoCapture* ptrCaptureStream, Mat* ptrMatCaptureSrc)
    {
    (*ptrCaptureStream) >> (*ptrMatCaptureSrc);
    }

/*------------------*\
 |*	get	     *|
 \*-----------------*/

int CaptureCamera::getIdCamera()
    {
    return idCamera;
    }

int CaptureCamera::dtOriginalMS()
    {
    return 0; // On doit attendre sur le port usb, mieux?
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

VideoCapture* CaptureCamera::createStream(int idCamera, int wAsk, int hAsk)
    {
    VideoCapture* ptrCaptureStream = new VideoCapture(idCamera);

    // VideoCapture* ptrCaptureStream = getVideoCapture();

    // cout << "(w,h) asked = (" << wAsk << "," << hAsk << ") asked" << endl;

    // Proposition
    if (wAsk != -1)
	{
	ptrCaptureStream->set(CV_CAP_PROP_FRAME_WIDTH, wAsk);
	}

    if (hAsk != -1)
	{
	ptrCaptureStream->set(CV_CAP_PROP_FRAME_HEIGHT, hAsk);
	}

    return ptrCaptureStream;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

