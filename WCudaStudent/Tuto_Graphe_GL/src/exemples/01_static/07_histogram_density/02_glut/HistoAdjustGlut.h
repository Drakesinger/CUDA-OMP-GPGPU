#ifndef HISTO_ADJUST_GLUT_H_
#define HISTO_ADJUST_GLUT_H_

#include "HistoAdjustGraphe.h"
#include "GLUTGraphWindow.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class HistoAdjustGlut
    {

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	HistoAdjustGlut(int w, int h, int px, int py);

	virtual ~HistoAdjustGlut();

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

	// Tools
	HistoAdjustGraphe* ptrGraphe;
	GLUTGraphWindow* ptrGLUTGraphWindow;

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
