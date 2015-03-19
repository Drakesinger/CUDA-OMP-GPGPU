#ifndef SRC_CPP_CORE_02_MANDELBROT_JULIA_JOE_C_MATH_MANDELBROT_H_
#define SRC_CPP_CORE_02_MANDELBROT_JULIA_JOE_C_MATH_MANDELBROT_H_

#include "Fractal.h"
/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class Mandelbrot: public Fractal
    {
    public:
	Mandelbrot(int n);
	virtual ~Mandelbrot();

	virtual int computeIndiceArret(double x, double y);
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
