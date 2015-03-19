#include "GaussCurve.h"
#include "GaussTools.h"

#include <cmath>

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
|*		Constructor		*|
 \*-------------------------------------*/

GaussCurve::GaussCurve(Title title, Apparance apparance, float mean, float stdDev) :
	CurveAnalytic(title, apparance), mean(mean), stdDev(stdDev)
    {
    this->maxDensity = GaussTools::maxDensity(mean, stdDev);
    }

GaussCurve::~GaussCurve()
    {
    // Nothing
    }

/*--------------------------------------*\
|*		Methode			*|
 \*-------------------------------------*/

float GaussCurve::f(const float x) const
    {
    double expo = ((x - mean) * (x - mean)) / (2 * stdDev * stdDev);
    return maxDensity * exp(-expo);
    }

Domaine GaussCurve::computeDomaine(const Domaine& graphDomaine) const
    {
    Interval intervalY(0.0, maxDensity);
    return Domaine(graphDomaine.getIntervalX(), intervalY);
    }

float GaussCurve::getMaxDensity() const
    {
    return maxDensity;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

