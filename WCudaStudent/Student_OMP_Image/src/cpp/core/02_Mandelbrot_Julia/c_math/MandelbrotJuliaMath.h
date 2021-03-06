#ifndef MANDELBROTJULIA_MATH_H_
#define MANDELBROTJULIA_MATH_H_

#include "CalibreurF.h"
#include "ColorTools.h"
#include <math.h>
#include "Fractal.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * Dans un header only pour preparer la version cuda
 */
class MandelbrotJuliaMath
    {
	/*--------------------------------------*\
	 |*		Constructeur		*|
	 \*-------------------------------------*/

    public:

	MandelbrotJuliaMath(int n, int _nMin):calibreur(IntervalF(0, n), IntervalF(0, 1))
	    {
	    this->fractal = fractal;
	    this->n = n;
	    }

	virtual ~MandelbrotJuliaMath(void)
	    {
	    // rien
	    }

	/*--------------------------------------*\
	|*		Methode			*|
	 \*-------------------------------------*/

    public:

	void colorXY(uchar4* ptrColor, float x, float y, const DomaineMath& domaineMath)
	    {
	    int k = fractal->computeIndiceArret(x, y);

	    if(k <= this->n)
	       {

		float z = k;
		calibreur.calibrer(z);

		float hue01 = z;

		ColorTools::HSB_TO_RVB(hue01, ptrColor); // update color
	       }
	    else
	       {
	       ptrColor->x = 0;
	       ptrColor->y = 0;
	       ptrColor->z = 0;
	       }

	    ptrColor->w = 255; // opaque
	    }

    private:

	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    protected:

	// Inputs
	int n;
	Fractal *fractal;
	// Tools
	CalibreurF calibreur;
    }
;

#endif

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
