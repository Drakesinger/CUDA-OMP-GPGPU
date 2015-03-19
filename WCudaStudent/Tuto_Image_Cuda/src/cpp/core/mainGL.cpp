#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "GLUTImageViewers_GPU.h"

#include "Device.h"
#include "cudaTools.h"

#include "WarmupProvider.h"
#include "VagueProvider.h"
#include "DamierProvider.h"
#include "AdvancedProvider.h"
#include "AdvancedDomaineProvider.h"

#include "MyDisplayableProvider.h"
#include "MyGLUTWindow.h"

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

    WarmupImage* ptrWarmup=WarmupProvider::createGL();

    Image* ptrVague=VagueProvider::createGL();
    ImageFonctionel* ptrDamier=DamierProvider::createGL();
    ImageFonctionel* ptrAdvancedListener=AdvancedProvider::createGL();
    Displayable_A* ptrMyDisplayable=MyDisplayableProvider::createGL();
    ImageFonctionel* ptrAdvancedDomaine=AdvancedDomaineProvider::createGL();


    // ImageViewer : (boolean,boolean) : (isAnimation,isSelectionEnable)
    GLUTImageViewers warmupViewer(ptrWarmup, true, false, 0, 0);
    GLUTImageViewers vagueViewer(ptrVague, true, false, 25,25);
    GLUTImageViewers damierlViewer(ptrDamier, true, true, 50, 50);
    GLUTImageViewers advancedListenerViewer(ptrAdvancedListener, true, true, 75, 75);
    GLUTImageViewers advancedDomaineViewer(ptrAdvancedDomaine, true, true, 100, 100);
    // Insert here other ImageViewer ...

    // OpenGLViewer
    MyGLUTWindow myGlutWindow(ptrMyDisplayable,"OpenGL : Custom Displayable",600,600,100,100);// scene OpenGL // (w,h,px,py)

    GLUTImageViewers::runALL(); // Bloquant, Tant qu'une fenetre est ouverte

    // destruction
	{
	delete ptrWarmup;
	delete ptrVague;
	delete ptrDamier;
	delete ptrAdvancedListener;
	delete ptrMyDisplayable;
	delete ptrAdvancedDomaine;

	ptrWarmup = NULL;
	ptrVague=NULL;
	ptrDamier = NULL;
	ptrAdvancedListener = NULL;
	ptrMyDisplayable = NULL;
	ptrAdvancedDomaine = NULL;
	}

    return EXIT_SUCCESS;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/




/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

