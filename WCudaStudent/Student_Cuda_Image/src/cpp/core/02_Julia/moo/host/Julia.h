#ifndef JULIA_H_
#define JULIA_H_

#include "cudaTools.h"
#include "AnimableFonctionel_I.h"
#include "MathTools.h"
#include "DomaineMath.h"
#include "VariateurI.h"

class Julia: public AnimableFonctionel_I
    {
    public:

	Julia(int w, int h, DomaineMath* domaineMath, int nMin, int nMax, float dt, float cx, float cy);
	virtual ~Julia(void);

	virtual void process(uchar4* ptrDevPixels,int w, int h,const DomaineMath& domaineMath);

	virtual void animationStep(void);
	virtual float getAnimationPara();

	virtual int getW(void);
	virtual int getH(void);
	virtual DomaineMath* getDomaineMathInit(void);
	virtual float getT(void);
	virtual string getTitle(void);

    private:

	// Inputs
	int w;
	int h;
	int n;
	int nMin;
	int nMax;
	float cx;
	float cy;
	VariateurI variateurAnimation;
	DomaineMath* ptrDomaineMathInit;
	float t; // para animation

	// Tools
	dim3 dg;
	dim3 db;

	//Outputs
	string title;
    };

#endif

