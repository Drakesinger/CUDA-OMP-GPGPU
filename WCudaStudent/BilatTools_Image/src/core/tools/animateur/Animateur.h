#ifndef ANIMATEUR_H_
#define ANIMATEUR_H_

#include "Animable_I.h"
#include "Chronos.h"
#include "Runnable_I.h"

using std::string;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class Animateur: public Runnable_I
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	/**
	 * Hyp:
	 * 	(H1) nbIteration suffisamment grand pour que timeElapse soit significatif
	 */
	Animateur(Animable_I* ptrAnimable, int nbIteration = 1000);
	virtual ~Animateur(void);

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
	Animable_I* ptrAnimable;

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

