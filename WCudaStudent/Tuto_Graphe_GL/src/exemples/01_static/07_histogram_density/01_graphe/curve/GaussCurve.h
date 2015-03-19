#ifndef GAUSS_CURVE_H_
#define GAUSS_CURVE_H_

#include "CurveAnalytic.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class GaussCurve: public CurveAnalytic
    {

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	GaussCurve(Title title, Apparance apparance, float mean, float stdDev);

	virtual ~GaussCurve();

	/*--------------------------------------*\
	|*		Methode			*|
	 \*-------------------------------------*/

    public:

	/**
	 *Override
	 */
	virtual float f(const float x) const;

	/**
	 *Override
	 */
	virtual Domaine computeDomaine(const Domaine& graphDomaine) const;

	/*----------*\
	 |*   Get    *|
	 \*---------*/

	float getMaxDensity() const;

	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	float mean;
	float stdDev;

	// Tools
	float maxDensity;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
