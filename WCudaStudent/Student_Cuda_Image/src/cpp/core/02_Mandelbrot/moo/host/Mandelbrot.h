#ifndef MANDELBROT_H_
#define MANDELBROT_H_

#include "cudaTools.h"
#include "AnimableFonctionel_I.h"
#include "MathTools.h"
#include "DomaineMath.h"
#include "VariateurI.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class Mandelbrot: public AnimableFonctionel_I
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	Mandelbrot(int w, int h, DomaineMath* domaineMath, int nMin, int nMax, float dt);
	virtual ~Mandelbrot(void);

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	/*----------------*\
	|*  Override	  *|
	 \*---------------*/

	virtual void process(uchar4* ptrDevPixels,int w, int h,const DomaineMath& domaineMath);
	virtual void animationStep(void);
	virtual float getAnimationPara();

	virtual int getW(void);
	virtual int getH(void);
	virtual DomaineMath* getDomaineMathInit(void);
	virtual float getT(void);
	virtual string getTitle(void);

    private:

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	int w;
	int h;
	int n;
	int nMin;
	int nMax;
	float t; // para animation
	VariateurI variateurAnimation;
	DomaineMath* ptrDomaineMathInit;

	// Tools
	dim3 dg;
	dim3 db;

	//Outputs
	string title;
    };

#endif

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
