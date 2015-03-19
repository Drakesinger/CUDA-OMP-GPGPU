#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "GLUTImageViewers.h"

#include "Device.h"
#include "cudaTools.h"

#include "RipplingProvider.h"
#include "MandelbrotProvider.h"
#include "NewtonProvider.h"
#include "RayTracingProvider.h"

using std::cout;
using std::endl;
using std::string;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int mainGL(void);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int mainGL(void)
    {
    cout << "\n[OpenGL] mode" << endl;

    //Image* ptrRippling = RipplingProvider::createGL();
    //ImageFonctionel* ptrMandelbrot = MandelbrotProvider::createGL();
    //ImageFonctionel* ptrNewton = NewtonProvider::createGL();
    ImageFonctionel_A* ptrRaytracing = RayTracingProvider::createGL();

    //ImageViewer : (boolean,boolean) : (isAnimation,isSelectionEnable)
    //GLUTImageViewers ripplingViewer(ptrRippling, true, false, 10, 10);
    //GLUTImageViewers mandelbrotViewer(ptrMandelbrot, true,true,10,10);
    //GLUTImageViewers newtonViewer(ptrNewton, true,true,10,10);
    GLUTImageViewers raytracingViewer(ptrRaytracing, true, false, 10,10);

    GLUTImageViewers::runALL(); // Bloquant, Tant qu'une fenetre est ouverte

    // destruction
	{
	//delete ptrRippling;
	//delete ptrMandelbrot;
	//delete ptrNewton;
	delete ptrRaytracing;

	//ptrRippling = NULL;
	//ptrMandelbrot = NULL;
	//ptrNewton = NULL;
	ptrRaytracing = NULL;
	}

    return EXIT_SUCCESS;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

