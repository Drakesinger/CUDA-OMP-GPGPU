#ifndef MANDELBROT_MATH_H_
#define MANDELBROT_MATH_H_

#include <math.h>
#include "ColorTools_GPU.h"
#include "CalibreurF.h"
#include "ColorTools.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class MandelbrotMath
    {

	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	__device__ MandelbrotMath(int n):calibreur(IntervalF(0, n), IntervalF(0, 1))
	    {
	    this->n = n;
	    }

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:
	__device__ void colorXY(uchar4* ptrColor, float x, float y, const DomaineMath& domaineMath)
		    {
		    int k = computeIndiceArret(x, y);

		    if(k <= this->n)
		       {
			float hue01 = (float) k;
			calibreur.calibrer(hue01);

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

	__device__  int computeIndiceArret(double x, double y)
	    {
	    int k = 0;
	    double a = x;
	    double b = y;
	    while (!isDivergent(a, b) && k <= this->n)
		{
		double aCopy = a;
		a = (a * a - b * b) + x;
		b = 2 * aCopy * b + y;
		k += 1;
		}
	    return k;
	    }

	__device__ bool isDivergent(double a, double b)
	    {
	    return (a * a + b * b) > 4;
	    }

    private:

	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/

    private:


	// Inputs
	int n;
	// Tools
	CalibreurF calibreur;

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
