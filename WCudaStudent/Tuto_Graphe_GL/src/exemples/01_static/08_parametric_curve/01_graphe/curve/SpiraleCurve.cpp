#include "SpiraleCurve.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

SpiraleCurve::SpiraleCurve(Title title, Apparance apparance, float x0, float y0, int k, int m, int nbPoints) :
	CurveParametric(title, apparance)
    {
    // Nothing
    this->x0 = x0;
    this->y0 = y0;
    this->k = k;
    this->m = m;
    this->nbPoints = nbPoints;
    }

SpiraleCurve::~SpiraleCurve()
    {
    // Nothing
    }

/**
 * Override
 */
int SpiraleCurve::getNbPoints() const
    {
    return nbPoints;
    }

/**
 * Override
 */
Interval SpiraleCurve::getIntervalLanda() const
    {
    return Interval(0, 2 * k * PI);
    }

/**
 * Override
 * landa in intervalLanda
 */
float SpiraleCurve::x(double landa) const
    {
    return x0 + r(landa) * cos(landa);
    }

/**
 * Override
 * landa in intervalLanda
 */
float SpiraleCurve::y(double landa) const
    {
    return y0 + r(landa) * sin(landa);
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

float SpiraleCurve::r(double landa) const
    {
    return landa * m / (2 * PI);
    }
/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

