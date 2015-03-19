#include "Julia.h"
/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

Julia::Julia(int n, double c1, double c2) :
	Fractal(n)
    {
    this->c1 = c1;
    this->c2 = c2;
    }

Julia::~Julia()
    {
    }

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int Julia::computeIndiceArret(double x, double y)
    {
    int k = 0;
    double a = x;
    double b = y;

    while (!isDivergent(a, b) && k <= this->n)
	{
	double aCopy = a;
	a = (a * a - b * b) + c1;
	b = 2 * aCopy * b + c2;
	k += 1;
	}
    return k;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
