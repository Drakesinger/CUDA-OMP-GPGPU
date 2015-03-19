#ifndef SINUS_CURVE_H_
#define SINUS_CURVE_H_

#include "CurveAnalytic.h"
#include <math.h>

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * Objectif :
 *
 * 	f(x) = a*sin(x+t)
 */
class SinusCurve: public CurveAnalytic
    {

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	SinusCurve(Title title, Apparance apparance, float a, float t = 0.0f, float dt = 0.001) :
		CurveAnalytic(title, apparance), a(a), t(t), dt(dt)
	    {
	    //Nothing
	    }

	virtual ~SinusCurve()
	    {
	    //Nothing
	    }

	/*--------------------------------------*\
	|*		Methode			*|
	 \*-------------------------------------*/

    public:

	/**
	 * Override
	 */
	virtual float f(const float x) const
	    {
	    return a * sin(x + t);
	    }

	/*----------------*\
	 |*	Set       *|
	 \*---------------*/

	void setA(float a)
	    {
	    this->a = a;
	    }

	/**
	 *  Override
	 * Call periodicaly
	 */
	virtual void animationStep()
	    {
	    t += dt;
	    }

	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	float a;
	float t;
	float dt;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
