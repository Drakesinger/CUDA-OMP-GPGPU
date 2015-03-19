#ifndef ANIMATEUR_FONCTIONEL_H_
#define ANIMATEUR_FONCTIONEL_H_

#include "AnimableFonctionel_I.h"
#include "Runnable_I.h"

using std::string;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class AnimateurFonctionel : public Runnable_I
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	/**
	 * Hyp:
	 * 	(H1) nbIteration suffisamment grand pour que timeElapse soit significatif
	 */
	AnimateurFonctionel(AnimableFonctionel_I* ptrAnimable, int nbIteration = 30000);
	virtual ~AnimateurFonctionel(void);

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	/**
	 * return fps
	 */
	int run(void);

	int getFps(void);

	void printStat(void);

    private:

	int start(void);

	void fpsProcess(void);

    private:

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

