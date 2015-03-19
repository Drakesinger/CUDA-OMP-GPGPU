#ifndef IMAGE_VIEVER_CV_H_
#define IMAGE_VIEVER_CV_H_

#include <string>
#include <opencv.hpp>
#include <highgui.hpp>

#include "Chronos.h"

using namespace cv;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class ImageVieverCV
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	ImageVieverCV(const string& titleFrame);
	virtual ~ImageVieverCV(void);

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:

	/**
	 * Warning : call cvWaitKey(1) after,sinon frame bloquer
	 */
	void show(Mat* ptrMatCapture);
	int fps(void);

	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/

    private:
	//Inputs
	string titleFrame;

	// Tools
	int compteur;
	Chronos chrono;

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
