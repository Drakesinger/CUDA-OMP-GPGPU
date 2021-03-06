#ifndef SINUS_GLUT_H_
#define SINUS_GLUT_H_

#include "SinusGraphe.h"
#include "GLUTGraphWindow.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class SinusGlut
    {

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	SinusGlut(int w, int h, int px, int py);

	virtual ~SinusGlut();

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	SinusGraphe* getSinusGraphe();

	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

	// Tools
	SinusGraphe* ptrGraphe;
	GLUTGraphWindow* ptrGLUTGraphWindow;

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
