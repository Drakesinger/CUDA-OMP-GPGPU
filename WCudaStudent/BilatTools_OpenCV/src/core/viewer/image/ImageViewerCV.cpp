#include "ImageViewerCV.h"



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

ImageVieverCV::ImageVieverCV(const string& titleFrame) :
	chrono()
    {
    this->titleFrame = titleFrame;
    //namedWindow(idWindow, 1);
    compteur = 0;
    }

ImageVieverCV::~ImageVieverCV(void)
    {
    // rien
    }

void ImageVieverCV::show(Mat* ptrMatCapture)
    {
    imshow(titleFrame, *ptrMatCapture);
    compteur++;
    }

int ImageVieverCV::fps(void)
    {
    double delayS = chrono.timeFlight();
    int fps = compteur / delayS;

    if (delayS > 2.0) //disons
	{
	compteur = 0;
	chrono.start();
	}

    return fps;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

