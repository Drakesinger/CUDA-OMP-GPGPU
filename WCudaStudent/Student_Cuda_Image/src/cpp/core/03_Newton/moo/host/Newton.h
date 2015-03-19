#ifndef NEWTON_H_
#define NEWTON_H_

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

class Newton: public AnimableFonctionel_I
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	Newton(int w, int h, DomaineMath* domaineMath, int nMin, int nMax, float dt, float epsilon);
	virtual ~Newton(void);

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	/*----------------*\
	|*  Override	  *|
	 \*---------------*/

	virtual void animationStep(void);

	virtual void process(uchar4* ptrDevPixels, int w, int h, const DomaineMath& domaineMath);
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
	float epsilon;

	DomaineMath* ptrDomaineMathInit;

	VariateurI variateurN;
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
