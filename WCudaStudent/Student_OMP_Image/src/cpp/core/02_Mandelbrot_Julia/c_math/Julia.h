#ifndef SRC_CPP_CORE_02_MANDELBROT_JULIA_JOE_C_MATH_JULIA_H_
#define SRC_CPP_CORE_02_MANDELBROT_JULIA_JOE_C_MATH_JULIA_H_

#include "Fractal.h"
/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class Julia: public Fractal
    {
    public:
	Julia(int n, double c1, double c2);
	virtual ~Julia();

	virtual int computeIndiceArret(double x, double y);

    private:
	double c1;
	double c2;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
