#ifndef SPIRALCURVE_H_
#define SPIRALCURVE_H_

#include "CurveParametric.h"
#include <math.h>

static double PI = 3.1415926538979;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 *  Objectif :
 *
 *	 x(landa) = x0 + r(landa)*cos(landa) landa in [0,2PI*k]
 *
 *	 y(landa) = y0 + r(landa)*sin(landa) landa in [0,2PI*k]
 *
 *	 avec :
 *
 *		r(landa) = landa*m/2PI
 *
 */
class SpiraleCurve: public CurveParametric
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	SpiraleCurve(Title title, Apparance apparance, float x0, float y0, int k, int m, int nbPoints);

	virtual ~SpiraleCurve();

	/*--------------------------------------*\
	|*		Methode			*|
	 \*-------------------------------------*/

    public:

	/**
	 * Override
	 */
	virtual int getNbPoints() const;

	/**
	 * Override
	 */
	virtual Interval getIntervalLanda() const;

	/**
	 * Override
	 * landa in intervalLanda
	 */
	virtual float x(double landa) const;

	/**
	 * Override
	 * landa in intervalLanda
	 */
	virtual float y(double landa) const;

    private:

	float r(double landa) const;

	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	float x0;
	float y0;
	int k;
	int m;
	int nbPoints;

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
