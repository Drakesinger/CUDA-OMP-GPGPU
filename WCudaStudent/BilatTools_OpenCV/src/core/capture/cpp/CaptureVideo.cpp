#include <iostream>
#include "CaptureVideo.h"

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
CaptureVideo::CaptureVideo(const string& videoName, const string& title, uchar4* ptrHostMemory) :
	Capture_A(createStream(videoName), title, ptrHostMemory)
    {
    //cout << "[CaptureVideo] : CaptureVideo" << endl;
    this->videoName = videoName;
    configure();
    }

CaptureVideo::~CaptureVideo(void)
    {
    // rien
    //  delete ptrCaptureStream; in constructor
    }

/*------------------*\
 |*	Methode	     *|
 \*-----------------*/

void CaptureVideo::printInfo(void)
    {
    Capture_A::printInfo();

    cout << "\tvideo name   = " << videoName << endl;

    if (isFpsSourceConnu)
	{
	cout << "\tfps(source)  = " << fpsSource << endl;
	}
    else
	{
	cout << "\tfps(source)  = Inconnu" << endl;
	}

    cout << endl;
    }

void CaptureVideo::readStream(VideoCapture* ptrCaptureStream, Mat* ptrMatCaptureSrc)
    {
    //cout << "[CaptureVideo] : readStream" << endl;

    // plante si fin cideo
    // (*ptrCaptureStream) >> (*ptrMatCaptureSrc);

    // mieux
   // cout << "[CaptureVideo] : read : try" << endl;
    bool isOk = ptrCaptureStream->read(*ptrMatCaptureSrc);
   // cout << "[CaptureVideo] : read : sucess" << endl;

    bool isFinVideo = !isOk;
    if (isFinVideo)
	{
	ptrCaptureStream->set(CV_CAP_PROP_POS_FRAMES, 0); // remise du lecteur à la position 0
	ptrCaptureStream->read(*ptrMatCaptureSrc);
	}
    }

/*------------------*\
 |*	get	     *|
 \*-----------------*/

int CaptureVideo::dtOriginalMS()
    {
    return dtSourceMS;
    }

int CaptureVideo::fpsOriginal()
    {
    return fpsSource;
    }

/*------------------*\
 |*	is	     *|
 \*-----------------*/

bool CaptureVideo::isFpsOriginalKnown()
    {
    return isFpsSourceConnu;
    }

string CaptureVideo::getVideoName()
    {
    return videoName;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

VideoCapture* CaptureVideo::createStream(const string& videoName)
    {
    return new VideoCapture(videoName);
    }

void CaptureVideo::configure()
    {
    //cout << "[CaptureVideo] : configure" << endl;

    //VideoCapture* ptrCaptureStream = getVideoCapture();

    this->fpsSource = ptrCaptureStream->get(CV_CAP_PROP_FPS); // TODO bug? always 1000 windows

    // cout << "fps video source (" << videoName << ") = ";

    if (fpsSource != 0)
	{
	this->isFpsSourceConnu = true;
	this->dtSourceMS = 1000 / fpsSource;

	//cout << fps << endl << endl;
	}
    else
	{
	this->isFpsSourceConnu = false;
	this->dtSourceMS = 0;

	//cout << "fps unknown" << endl << endl;
	}
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

