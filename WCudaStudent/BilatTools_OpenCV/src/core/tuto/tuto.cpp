#include <iostream>

#include <opencv.hpp>
#include <highgui.hpp>

using std::cout;
using std::cerr;
using std::endl;
using std::string;

using namespace cv;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int tuto(string nameVideo);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static int work(VideoCapture* ptrVideoCapture);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * http://docs.opencv.org/doc/tutorials/highgui/video-input-psnr-ssim/video-input-psnr-ssim.html
 */
int tuto(string nameVideo)
    {

    try
	{
	//v1
	//  VideoCapture cap(nameVideo);

	//v2
	VideoCapture cap;
	cap.open(nameVideo);

	if (!cap.isOpened())
	    {
	    return EXIT_FAILURE;
	    }

	else
	    {
	    return work(&cap);
	    }

	}
    catch (cv::Exception& e)
	{
	const char* err_msg = e.what();

	cerr << "Tuto failed" << endl;
	cerr << err_msg << endl;

	return EXIT_FAILURE;
	}

    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

int work(VideoCapture* ptrVideoCapture)
    {
    cout<<"[Tuto] : work"<<endl;

    VideoCapture cap = *ptrVideoCapture;

    double rate = cap.get(CV_CAP_PROP_FPS);
    int delay = 1000/rate;

    namedWindow("edges", 1);

    Mat edges;
    while (true)
	{
	Mat frame;
	//cout << "[Tuto] cap >> frame : try" << endl; // debug
	cap >> frame; // get a new frame from camera

	if (frame.empty())
	    {
	    return EXIT_SUCCESS;
	    }
	else
	    {
	    // ColorConversion
		{
		// http://siggiorn.com/wp-content/uploads/libraries/opencv-java/docs/sj/opencv/Constants.ColorConversion.html
		//int colorConversion=CV_BGR2GRAY; // ok
		//int colorConversion=CV_BGR2RGBA ; // ko
		int colorConversion = CV_BGR2BGRA;     		// ok
		cvtColor(frame, edges, colorConversion);
		}

	    // Effet
		{
		//GaussianBlur(edges, edges, Size(7, 7), 1.5, 1.5);
		//Canny(edges, edges, 0, 30, 3);
		}

	    imshow("edges", edges);

	    if (waitKey(delay) >= 0)
		{
		return EXIT_SUCCESS;
		}
	    }
	}
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

