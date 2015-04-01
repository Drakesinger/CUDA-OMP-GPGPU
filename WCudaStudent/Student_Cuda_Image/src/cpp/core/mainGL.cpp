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
#include "RayTracingSMProvider.h"
#include "JuliaProvider.h"
#include "MandelbrotProvider.h"
#include "HeatTransfertProvider.h"

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
    /* Lanceur originaux - 1 à la fois */
    //Image* ptrRippling = RipplingProvider::createGL();
    //ImageFonctionel* ptrJulia = JuliaProvider::createGL();
    //ImageFonctionel* ptrMandelbrot = MandelbrotProvider::createGL();
    //ImageFonctionel* ptrNewton = NewtonProvider::createGL();
    //Image* ptrRaytracing = RayTracingProvider::createGL();
    //Image* ptrRaytracingSM = RayTracingSMProvider::createGL();
    Image* ptrheattransfert = HeatTransfertProvider::createGL();

    //ImageViewer : (boolean,boolean) : (isAnimation,isSelectionEnable)
    //GLUTImageViewers ripplingViewer(ptrRippling, true, false, 10, 20);
    //GLUTImageViewers juliaViewer(ptrJulia, true,true,10,10);
    //GLUTImageViewers mandelbrotViewer(ptrMandelbrot, true,true,10,10);
    //GLUTImageViewers newtonViewer(ptrNewton, true,true,10,10);
    //GLUTImageViewers raytracingViewer(ptrRaytracing, true, false, 10,10);
    //GLUTImageViewers raytracingSMViewer(ptrRaytracingSM, true, false, 10,10);

    GLUTImageViewers heattransfertViewer(ptrheattransfert, true, false, 10,10);

    /* Lancer toutes les animations à la fois */
    /*Image* ptrRippling = RipplingProvider::createGL();
    ImageFonctionel* ptrJulia = JuliaProvider::createGL();
    ImageFonctionel* ptrMandelbrot = MandelbrotProvider::createGL();
    ImageFonctionel* ptrNewton = NewtonProvider::createGL();
    Image* ptrRaytracing = RayTracingProvider::createGL();
    Image* ptrRaytracingSM = RayTracingSMProvider::createGL();

    //ImageViewer : (boolean,boolean) : (isAnimation,isSelectionEnable)
    GLUTImageViewers ripplingViewer(ptrRippling, true, false, 0, 0);
    GLUTImageViewers juliaViewer(ptrJulia, true,true,350,0);
    GLUTImageViewers mandelbrotViewer(ptrMandelbrot, true,true,700,0);
    GLUTImageViewers newtonViewer(ptrNewton, true,true,0,370);
    GLUTImageViewers raytracingViewer(ptrRaytracing, true, false, 350,370);
    GLUTImageViewers raytracingSMViewer(ptrRaytracingSM, true, false, 700,370);*/

    GLUTImageViewers::runALL(); // Bloquant, Tant qu'une fenetre est ouverte
    // destruction
	{
	//delete ptrRippling;
	//delete ptrJulia;
	//delete ptrMandelbrot;
	//delete ptrNewton;
	//delete ptrRaytracing;
	//delete ptrRaytracingSM;
	delete ptrheattransfert;

	//ptrRippling = NULL;
	//ptrJulia = NULL;
	//ptrMandelbrot = NULL;
	//ptrNewton = NULL;
	//ptrRaytracing = NULL;
	//ptrRaytracingSM = NULL;
	ptrheattransfert = NULL;
	}

    return EXIT_SUCCESS;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

