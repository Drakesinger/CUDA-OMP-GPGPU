#ifndef DISCRET_CURVE_GLUT_H_
#define DISCRET_CURVE_GLUT_H_

#include "GLUTGraphWindow.h"
#include "DiscretCurveGraph.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class DiscretCurveGlut
    {

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	DiscretCurveGlut(int w, int h, int px, int py);

	virtual ~DiscretCurveGlut();

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

	// Tools
	DiscretCurveGraph* ptrGraphe;
	GLUTGraphWindow* ptrGLUTGraphWindow;

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
