#ifndef ANIMATED_MANUEL_GLUT_H
#define ANIMATED_MANUEL_GLUT_H

#include "Graph.h"
#include "GLGraph.h"
#include "GLUTWindow.h"
#include "SinusGraphe.h"

class AnimateManuelGlut
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	AnimateManuelGlut(int w, int h, int px, int py);
	virtual ~AnimateManuelGlut();

	/*--------------------------------------*\
	|*		Methode			*|
	 \*-------------------------------------*/

    public:

	/**
	 * Bloquant, tant que fenetre ouverte
	 */
	void run(void);

    private:

	void createGraph();
	void createGLGraph();
	void createGLUTWindow(int w, int h, int px, int py);

	void animer(void);

	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

	// Tools
	GLGraph* ptrGlGraph;
	GLUTWindow* ptrGlutWindow;
	SinusGraphe* ptrSinusGraphe;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
