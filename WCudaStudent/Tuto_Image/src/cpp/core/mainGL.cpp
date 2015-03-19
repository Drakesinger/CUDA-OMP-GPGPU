#include <iostream>

#include "GLUTImageViewers.h"

#include "WarmupProvider.h"
#include "VagueProvider.h"
#include "DamierProvider.h"
#include "AdvancedProvider.h"
#include "AdvancedDomaineProvider.h"

#include "MyDisplayableProvider.h"
#include "MyGLUTWindow.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported		*|
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


/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

int mainGL(void)
    {
    cout << "\n[OpenGL] mode" << endl;

    WarmupImage* ptrWarmup = WarmupProvider::createGL();

    Image* ptrVague = VagueProvider::createGL();
    ImageFonctionel* ptrDamier = DamierProvider::createGL();
    AdvancedImage* ptrAdvanced = AdvancedProvider::createGL();
    ImageFonctionel* ptrAdvancedDomain = AdvancedDomaineProvider::createGL();

    // ImageViewer : (boolean,boolean) : (isAnimation,isSelectionEnable)
    GLUTImageViewers warmupViewer(ptrWarmup, true, false, 0, 0);
    GLUTImageViewers vagueViewer(ptrVague, true, false, 20, 20);
    GLUTImageViewers damierViewer(ptrDamier, true, true, 40, 40);
    GLUTImageViewers advancedViewer(ptrAdvanced, true, false, 80, 80);
    GLUTImageViewers advancedDomaineViewer(ptrAdvancedDomain, true, true, 100, 100);
    // Insert here other ImageViewer ...

    // OpenGLViewer (Advanced)
    Displayable_A* ptrMyDisplayable = MyDisplayableProvider::createGL();
    MyGLUTWindow myGlutWindow(ptrMyDisplayable, "Triangle OpenGL Custom Displayable", 600, 600, 100, 100); // scene OpenGL // (w,h,px,py)

    GLUTImageViewers::runALL();  // Bloquant, Tant qu'une fenetre est ouverte

    // destruction
	{
	delete ptrWarmup;
	delete ptrVague;
	delete ptrDamier;
	delete ptrAdvanced;
	delete ptrAdvancedDomain;

	ptrWarmup = NULL;
	ptrVague = NULL;
	ptrDamier = NULL;
	ptrAdvanced = NULL;
	ptrAdvancedDomain = NULL;
	}

    return EXIT_SUCCESS;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

