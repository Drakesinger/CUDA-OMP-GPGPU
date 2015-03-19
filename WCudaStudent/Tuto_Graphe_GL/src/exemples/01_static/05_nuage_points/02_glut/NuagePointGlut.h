#ifndef NUAGE_POINT_GLUT_H_
#define NUAGE_POINT_GLUT_H_

#include "NuagesPointsGraphe.h"
#include "GLUTGraphWindow.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class NuagePointGlut
    {

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	NuagePointGlut(int w, int h, int px, int py);

	virtual ~NuagePointGlut();

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

	// Tools
	NuagesPointsGraphe* ptrGraphe;
	GLUTGraphWindow* ptrGLUTGraphWindow;

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
