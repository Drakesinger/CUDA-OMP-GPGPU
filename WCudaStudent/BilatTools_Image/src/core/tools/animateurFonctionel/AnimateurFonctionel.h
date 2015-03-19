#ifndef ANIMATEUR_FONCTIONEL_H_
#define ANIMATEUR_FONCTIONEL_H_

#include "AnimableFonctionel_I.h"
#include "Chronos.h"
#include "Runnable_I.h"

using std::string;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class AnimateurFonctionel:public Runnable_I
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	/**
	 * Hyp:
	 * 	(H1) nbIteration suffisamment grand pour que timeElapse soit significatif
	 * 	(H2) ptrAnimable image uchar4
	 */
	AnimateurFonctionel(AnimableFonctionel_I* ptrAnimable, int nbIteration = 1000);
	virtual ~AnimateurFonctionel(void);

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	/**
	 * return fps
	 */
	int run();

	int getFps(void);
	void printStat(void);

    private:

	/**
	 * return fps
	 */
	int start(void);
	void fpsProcess();

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	int nbIteration;
	AnimableFonctionel_I* ptrAnimable;

	// Tools
	Chronos* ptrChrono;

	// Output
	int fps;
	float timeElapseS;

    };

#endif

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

