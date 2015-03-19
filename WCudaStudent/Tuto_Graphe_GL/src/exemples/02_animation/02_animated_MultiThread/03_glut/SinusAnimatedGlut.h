#ifndef SINUS_ANIMATED_GLUT_H_
#define SINUS_ANIMATED_GLUT_H_

#include "SinusGraphe.h"
#include "GLUTMultithreadWindow.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * Rappel:
 *
 * 	Glut est mono thread
 * 	Le glut-thread est même le main-thread
 *
 * Animation Standard (mecanismes par defaut)
 * 	Dans les examples precedents, l'animation etait orchestrer par idleFunc.
 * 	Glut apelle périodiquement dans son glut-thread le callback idleFunc.
 * 	idleFunc est redefini dans GLUTGraphWindow, qui appelle animationStep de Curve ou tout autre figure
 *
 * Animation:
 * 	L'objectif est ici d'utiliser un thread separer (donc different de glut-thread)
 * 	L'avantage est qu'ici il y a un thread fenetre,au lieu de 1 pour toute les fenêtres.
 * 	=> Plus performant si calcul complexe
 *
 * Note:
 * 	Les deux mécanimes d'animation peuvent cohabiter et être utiliser en meme temps.
 *
 * Technique:
 *
 * 	Cette animation dans cette api s'appelle animation "post-rendu", car une methode
 *
 * 		postRender
 *
 * 	est appeller après le rendu initial d'une fenêtre vide.
 * 	Dans cette méthode on code une boucle infinie qui joue l'animation.
 * 	Cette méthode est appeler par un autre que le glut-thread.
 * 	Ce thread est transparent pour l'utilisateur.
 *
 * Conclusion:
 *
 * 	Pour le user, il faut
 *
 * 		(C1) setAnimationEnable(true) sur son objet graphe
 * 		(C2) Utiliser GLUTMultithreadWindow au lieu de GLUTGraphWindow
 *
 */
class SinusAnimatedGlut
    {

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	SinusAnimatedGlut(int w, int h, int px, int py);

	virtual ~SinusAnimatedGlut();

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public:


	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

	// Tools
	SinusGraphe* ptrGraphe;
	GLUTMultithreadWindow* ptrGLUTMultithreadWindow;

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
