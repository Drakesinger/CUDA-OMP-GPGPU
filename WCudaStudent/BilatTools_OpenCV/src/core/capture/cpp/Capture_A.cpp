#include <iostream>
#include "Capture_A.h"

using std::cerr;
using std::cout;
using std::endl;

//http://docs.opencv.org/doc/tutorials/highgui/video-input-psnr-ssim/video-input-psnr-ssim.html

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
 * Optimisation Cuda:
 * 	Principe:
 *		Use pinned memory in host side
 *		Give this area to openCV
 * 	Syntaxe:
 * 		size_t sizeOctets=w*h*sizeof(uchar4);
 * 		uchar4* ptrHostMemory;
 * 		HANDLE_ERROR( cudaHostAlloc ((void**) &ptrHostMemory, sizeOctets,cudaHostAllocDefault ) );
 *
 *  Usage:
 * 	CaptureVideo  captureur(pathToVideo, titre);
 *	Mat matImage=captureur.capturer(); // capture une image seulement ( à utiliser en boucle!)
 *	uchar4* image= CaptureVideo::castToUChar4(&matImage); // format cuda
 */
Capture_A::Capture_A(VideoCapture* ptrCaptureStream, const string& title, uchar4* ptrHostMemory):chrono()
    {
   // cout << "[Capture_A] : Capture_A" << endl;

    this->title = title;
    this->compteurCapture = 0;
    this->ptrCaptureStream = ptrCaptureStream;

    this->w = (int) ptrCaptureStream->get(CV_CAP_PROP_FRAME_WIDTH);
    this->h = (int) ptrCaptureStream->get(CV_CAP_PROP_FRAME_HEIGHT);
   // chrono=Chronos();

    if(ptrHostMemory!=NULL)
	{
	matCaptureSrc=Mat(w,h,CV_BGR2RGBA,ptrHostMemory); // Ecrase ancienne
	}
    }

Capture_A::~Capture_A(void)
    {
    if (ptrCaptureStream != NULL)
	{
	delete ptrCaptureStream;
	ptrCaptureStream = NULL;
	}
    }

/*------------------*\
 |*	Methode	     *|
 \*-----------------*/

Mat Capture_A::capturer(void)
    {
    //cout << "[Capture_A] : capturer" << endl;

    compteurCapture++;

    //(*ptrCaptureStream) >> matCaptureSrc; // plante en fin de video
    readStream(this->ptrCaptureStream, &this->matCaptureSrc); // methode virtuelle : au lieu de ci-dessous, plus robuste

    // debug
	{
	//printInfo();
	}

    // old
	{
	// Type image:
	// CV_8U CV_	=> BVRA et non RVBA => demande correction TODO Mieux?
	// RGB2GRAY
	// int nbChannel = 4; // 0 keep same chanel // 4 permet par exemple d'ajouter la couche alpha à rvb (pour une video ou webcam)
	// cvtColor(matCaptureSrc, matCaptureDest, CV_8U, nbChannel);
	}

    // new
	{
	// http://siggiorn.com/wp-content/uploads/libraries/opencv-java/docs/sj/opencv/Constants.ColorConversion.html
	//int colorConversion=CV_BGR2GRAY; // ok
	//int colorConversion=CV_BGR2RGBA ; // ko
	int colorConversion = CV_BGR2BGRA; // ok
	cvtColor(matCaptureSrc, matCaptureDest, colorConversion);
	}

    return matCaptureDest; //castToUChar4(matCapture.data);
    }

void Capture_A::printInfo(void)
    {
    cout << "[Capture_A] : Capture Info :" << endl;
    cout << "\t(w,h)        = (" << w << "," << h << ")" << endl;
    cout << "\ttitle        = " << title << endl;
    cout << "\tnbChannel    = " << matCaptureSrc.channels() << endl;
    cout << "\ttype         = " << matCaptureSrc.type() << endl;
    cout << "\tisEmpty      = " << matCaptureSrc.empty() << endl;
    cout << "\tdtMS(source) = " << dtOriginalMS() << endl;

    if (compteurCapture >= 2)
	{
	cout << "\tfps(capture) = " << fpsCapture() << endl;
	}

    cout << "\tchrono       = " << chrono.timeFlight() << " (s)"<< endl;
    cout << "\t#image       = " << compteurCapture << endl;
    }

int Capture_A::nbOctetImage()
    {
    return w * h * sizeof(uchar4);
    }

int Capture_A::fpsCapture()
    {
    double timeS = chrono.timeFlight();
    double fps = compteurCapture / timeS;

    return (int) fps;
    }

/*------------------*\
 |*	is	     *|
 \*-----------------*/

bool Capture_A::isOpened(void)
    {
    return ptrCaptureStream->isOpened();
    }

/*------------------*\
 |*	get	     *|
 \*-----------------*/

VideoCapture* Capture_A::getVideoCapture()
    {
    return ptrCaptureStream;
    }

int Capture_A::getW(void)
    {
    return w;
    }

int Capture_A::getH(void)
    {
    return h;
    }

int Capture_A::dtOriginalMS()
    {
    return 0;
    }

long Capture_A::nbCapture()
    {
    return compteurCapture;
    }

string Capture_A::getTitle()
    {
    return title;
    }

Chronos Capture_A::getChronos()
    {
    return chrono;
    }

/*--------------------------------------*\
 |*		Static			*|
 \*-------------------------------------*/

/**
 * uchar = unsigned char
 * uchar4 = 4 char sequentiel
 */
uchar4* Capture_A::castToUChar4(uchar* ptrTab)
    {
    return (uchar4*) ptrTab;
    }

/**
 * uchar = unsigned char
 * uchar4 = 4 char sequentiel
 */
uchar4* Capture_A::castToUChar4(Mat* ptrMap)
    {
    return castToUChar4(ptrMap->data);
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

// http://opencv.willowgarage.com/documentation/cpp/reading_and_writing_images_and_video.html#cv-videocapture-get
// TODO: fixme marche pas trop bien
// 	capture.set(CV_CAP_PROP_FRAME_WIDTH,1280);
//	capture.set(CV_CAP_PROP_FRAME_HEIGHT ,720);
//capture.set(CV_CAP_PROP_EXPOSURE,0);
//	 int n = matCapture.rows;
//	     int m = matCapture.cols;
//
//uchar* ptr=matCapture.data;
//	 unsigned char* ptr4=(unsigned char*)ptr;
// cout<<"size uchar = "<<sizeof(uchar)<<endl;
//	 cout<<"size unsigned char = "<<sizeof(unsigned char)<<endl;
//	 cout<<"size uchar4 = "<<sizeof(uchar4)<<endl;
//	 cout<<"n= "<<n<<endl;
//	 cout<<"m= "<<m<<endl;
//	 uchar* ptrCopy=new uchar[n*m];
//	 uchar* ptrAgain=ptrCopy;
//	 for(int i=1;i<=n*m*4;i++)
//	 	    {
//	     *ptr++=123;
//	 	    }
//cout<<"i"<<i<<endl;
// 	    *ptrCopy=*ptr4;
////	 	     ptrCopy++;
//	     *ptr4=123;
//	 	     ptr4++;
//
////	 	     //*ptrCopy=*ptr4;
////	 	     ptrCopy++;
////	 	     ptr4++;
////
////	 	     //*ptrCopy=*ptr4;
////	 	     ptrCopy++;
////	 	     ptr4++;
////
////	 	     //*ptrCopy=*ptr4;
////
////	 	     if(i<n*m)
////	 		 {
////	 	     ptrCopy++;
////
////	 	     ptr4++;
////	 		 }
//	 	    }
////	 for(int i=1;i<=n*m;i++)
////	    {
////	     //cout<<"i"<<i<<"\t";
////	     assert(ptr[i-1]==ptrAgain[i-1]);
////	    }
// CV_8U : [0,255]
// CV_16U : [0,65535]
// CV_32F : [0,1] in R
//cvtColor(matCapture, matCapture, CV_8U,0); // 0 keep same chanel
//  cvtColor(matCapture, matCapture, CV_8U,4); // 0 keep same chanel // 4 permet par exemple d'ajouter la couche alpha à rvb (pour une video ou webcam)
/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

