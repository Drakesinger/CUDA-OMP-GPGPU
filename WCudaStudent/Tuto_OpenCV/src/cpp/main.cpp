#include <iostream>

#include "CaptureVideo.h"
#include "CaptureCamera.h"
#include "Capture_A.h"
#include "SequenceViewerCV.h"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::string;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern int tuto(string nameVideo);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static int useVideo(void);
static int useCamera(void);
static int show(Capture_A* ptrCaptureur);
static string getVideoName(void);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * usecamera marche seulement avec un user à la fois!
 * Essayer aussi ouvrir camera avec vlc
 */
int main(void)
    {
    //tuto(getVideoName()); // debug

    return useVideo();
    //return useCamera();
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

int useVideo(void)
    {
    cout << "[use video]" << endl;

    string title = "Tuto Video";
    string videoName = getVideoName();
    CaptureVideo captureur(videoName, title);

    if (captureur.isOpened())
	{
	return show(&captureur); // bloquant
	}
    else
	{
	cerr << "\n[Tuto OpenCV] : Failed to open : " << videoName << endl;
	return EXIT_FAILURE;
	}
    }

string getVideoName(void)
    {
#ifdef _WIN32
    // Work
    // string nameVideo ="Q:\\neilPryde.avi";
    //  string nameVideo = "C:\\Users\\cedric.bilat\\Desktop\\neilPryde.avi"; // ok
    //string nameVideo="C:\\Users\\cedric.bilat\\Desktop\\nasaFHD_short.avi";//ok
    string nameVideo="C:\\Users\\cedric.bilat\\Desktop\\autoroute.mp4";//ok

    // Home
    //  string nameVideo = "C:\\Users\\bilat\\Desktop\\neilPryde.avi"; // ok
    //string nameVideo="C:\\Users\\bilat\\Desktop\\nasaFHD_short.avi";// ok
    //string nameVideo="C:\\Users\\bilat\\Desktop\\autoroute.mp4";// ok
#elif  __arm__
   // string nameVideo="/opt/data/neilPryde.avi"; //ok
    //string nameVideo="/opt/data/nasaFHD_short.avi"; //ko
    string nameVideo = "/opt/data/autoroute.mp4"; // ok
#else
    //string nameVideo = "/media/Data/Video/neilPryde.avi"; // ok
    //string nameVideo = "/media/Data/Video/nasaFHD_short.avi"; // ko
    string nameVideo = "/media/Data/Video/autoroute.mp4"; // ok
#endif

    cout<<"[use video] : "<<nameVideo<<endl;

    return nameVideo;
    }

int useCamera(void)
    {
    cout << "[use Camera]" << endl;

    int idCamera = 0;
    string title = "Tuto Camera";

    // CaptureCamera captureur(idCamera, title,320,160);
   // CaptureCamera captureur(idCamera, title);
   CaptureCamera captureur(idCamera, title,1920,1080);

    if (captureur.isOpened())
	{
	return show(&captureur);
	}
    else
	{
	return EXIT_FAILURE;
	}
    }

int show(Capture_A* ptrCaptureur)
    {
    SequenceVieverCV sequenceViever(ptrCaptureur);
    sequenceViever.run(); // bloquant
    return EXIT_SUCCESS;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

