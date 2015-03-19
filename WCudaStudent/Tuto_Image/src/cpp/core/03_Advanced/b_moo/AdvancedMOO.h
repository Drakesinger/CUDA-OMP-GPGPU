#ifndef ADVANCED_MOO_H_
#define ADVANCED_MOO_H_

#include "cudaType.h"
#include "Animable_I.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class AdvancedMOO: public Animable_I
    {

	/*--------------------------------------*\
	 |*		Constructeur		*|
	 \*-------------------------------------*/

    public:

	AdvancedMOO(unsigned int w, unsigned int h, float dt);
	virtual ~AdvancedMOO(void);

	/*--------------------------------------*\
	 |*		Methode			*|
	 \*-------------------------------------*/

    public:

	/*-------------------------*\
	|*   Override Animable_I   *|
	 \*------------------------*/

	/**
	 * Call periodicly by the api
	 */
	virtual void process(uchar4* ptrTabPixels, int w, int h);
	/**
	 * Call periodicly by the api
	 */
	virtual void animationStep();

	virtual float getAnimationPara();
	virtual string getTitle();
	virtual int getW();
	virtual int getH();

    private:

	// Balayage image
	void entrelacementOMP(uchar4* ptrTabPixels, int w, int h);
	void forAutoOMP(uchar4* ptrTabPixels, int w, int h);

	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	unsigned int w;
	unsigned int h;
	double dt;

	// Outputs
	string title;

	// Tools
	double t;
	bool isEntrelacement;
    };

#endif

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 /*----------------------------------------------------------------------*/
