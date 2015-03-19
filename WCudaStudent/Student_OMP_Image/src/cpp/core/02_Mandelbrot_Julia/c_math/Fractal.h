#ifndef SRC_CPP_CORE_02_MANDELBROT_JULIA_JOE_C_MATH_FRACTAL_H_
#define SRC_CPP_CORE_02_MANDELBROT_JULIA_JOE_C_MATH_FRACTAL_H_

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class Fractal
    {
    public:
	Fractal(int n);
	virtual ~Fractal();

	virtual int computeIndiceArret(double x, double y) = 0;

    protected:
	int n;
	bool isDivergent(double a, double b);

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
