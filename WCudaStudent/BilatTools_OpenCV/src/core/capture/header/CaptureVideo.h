#ifndef CAPTURE_VIDEO_H_
#define CAPTURE_VIDEO_H_

#include "Capture_A.h"

using namespace cv;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * http://opencv.willowgarage.com/wiki/VideoCodecs
 *
 * AVI 'I420' RAW I420 Uncompressed YUV, 4:2:0 chroma subsampled
 *
 * Soft convertion :
 * 	(S1) mencoder
 * 		http://www.mplayerhq.hu/design7/dload.html
 * 			console:  mencoder in.avi -ovc raw -vf format=i420 -oac mp3lame -o out.avi
 * 		http://smplayer.sourceforge.net/
 *
 *
 * 		sudo apt-get install mencoder
 *
 * 	(S2) VirtualDub
 */
class CaptureVideo: public Capture_A
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	CaptureVideo(const string& videoName, const string& title,uchar4* ptrHostMemory=NULL);
	virtual ~CaptureVideo(void);

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:

	/**
	 * Temps a attendre entre 2 captures pour respecter fps original
	 */
	int dtOriginalMS(void); // Override

	string getVideoName(void);

	void printInfo(void); // Override

	int fpsOriginal(void);
	bool isFpsOriginalKnown(void);

    private:

	void configure(void);
	VideoCapture* createStream(const string& videoName);

    protected:

	virtual void readStream(VideoCapture* ptrCaptureStream, Mat* ptrMatCaptureSrc);

	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	string videoName;

	// Outputs
	int dtSourceMS;
	bool isFpsSourceConnu;
	int fpsSource;

    };

#endif

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
