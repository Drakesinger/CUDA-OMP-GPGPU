#ifndef RAYTRACING_H_
#define RAYTRACING_H_

#include "cudaTools.h"
#include "AnimableFonctionel_I.h"
#include "MathTools.h"
#include "DomaineMath.h"
#include "../device/math/Sphere.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class RayTracing: public AnimableFonctionel_I
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	RayTracing(int w, int h, DomaineMath* domaineMath, const int NB_SPHERE, float dt);
	virtual ~RayTracing(void);

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



	static float randomMinMax(float min, float max);

    private:

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	const int NB_SPHERE;
	int w;
	int h;
	float t; // para animation
	float dt; // para animation
	DomaineMath* ptrDomaineMathInit;
	Sphere* ptrSpheres;
	Sphere* ptrDevSpheres;

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