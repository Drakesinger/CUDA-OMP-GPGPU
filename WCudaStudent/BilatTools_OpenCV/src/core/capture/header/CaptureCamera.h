#ifndef CAPTURE_CAMERA_H_
#define CAPTURE_CAMERA_H_


#include "Capture_A.h"

using namespace cv;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CaptureCamera: public Capture_A
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	/**
	 * wAsk=-1 hAsk=-1 => valeur par default camera
	 * wAsk=-2500 hAsk=1600 => valeur max camera, pas necessairement 2500x1600, mais max (strange, mais semble marcher)
	 */
	CaptureCamera(int idCamera,const string&  title, int wAsk = 2500, int hAsk = 1600,uchar4* ptrHostMemory=NULL);
	virtual ~CaptureCamera(void);

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:

	void printInfo(void); // Override
	int getIdCamera(void);
	int dtOriginalMS(void);// Override


    protected :

	virtual void readStream(VideoCapture* ptrCaptureStream, Mat* ptrMatCaptureSrc);

    private:

	void configure(void);
	VideoCapture* createStream(int idCamera,int wAsk, int hAsk );

	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	int idCamera;
	int wAsk;
	int hAsk;

    };

#endif

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
