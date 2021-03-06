#ifndef NEWTON_MATH_H_
#define NEWTON_MATH_H_

#include <math.h>
#include "ColorTools_GPU.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class NewtonMath
    {

	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	__device__ NewtonMath(float _epsilon, int _n):epsilon(_epsilon),n(_n)
	    {
	    }

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:
	__device__ void colorXY(uchar4* ptrColor, float x1, float x2, const DomaineMath& domaineMath)
	    {
	    int MultCol = 15;
	    bool converge = false;

	    int index = 0;
	    while(index++ <= n && !converge)
		{
		float x1Copy = x1;
		float x2Copy = x2;

		x1 = x1Next(x1, x2);
		x2 = x2Next(x1Copy, x2);

		computeIndiceArret(x1Copy, x2Copy, x1, x2, converge);
		}

	    ptrColor->x = 30;
	    ptrColor->y = 30;
	    ptrColor->z = 30;

	    if(converge)
		{
		double distA = distance(x1, xa1()) + distance(x2, xa2());
		double distB = distance(x1, xb1()) + distance(x2, xb2());
		double distC = distance(x1, xc1()) + distance(x2, xc2());

		if(distA < distB && distA < distC){
		    ptrColor->x = 255 - index*MultCol;
		    ptrColor->y = 0;
		    ptrColor->z = 0;
		}
		else if(distB < distC){
		    ptrColor->x = 0;
		    ptrColor->y = 255 - index*MultCol;
		    ptrColor->z = 0;
		}
		else{
		    ptrColor->x = 0;
		    ptrColor->y = 0;
		    ptrColor->z = 255 - index*MultCol;
		}
		}

	    ptrColor->w = 255; // opaque
	    }


	__device__ void computeIndiceArret(double x1, double x2, double x1Next, double x2Next, bool& converge) const
	    {
	    converge = (distance(x1, x1Next) + distance(x2, x2Next))/(x1Next*x1Next+x2Next*x2Next) < epsilon;
	    }

	__device__ float distance(const float x1, const float x2) const {return (x2-x1)*(x2-x1);}

	// f1 et f2
	__device__ float f1(const float x1, const float x2) const {return x1*x1*x1-3.0*x1*x2*x2-1.0;}
	__device__ float f2(const float x1, const float x2) const {return x2*x2*x2-3.0*x1*x1*x2;}

	//Inverse jacobienne
	__device__ float jf11(const float x1, const float x2) const {return (-3.0*x1*x1+3.0*x2*x2)/(-9.0*x1*x1*x1*x1-18.0*x1*x1*x2*x2-9.0*x2*x2*x2*x2);}
	__device__ float jf12(const float x1, const float x2) const {return (6.0*x1*x2)/(-9*x1*x1*x1*x1-18.0*x1*x1*x2*x2-9.0*x2*x2*x2*x2);}
	__device__ float jf21(const float x1, const float x2) const {return (6.0*x1*x2)/(-9*x1*x1*x1*x1-18.0*x1*x1*x2*x2-9.0*x2*x2*x2*x2);}
	__device__ float jf22(const float x1, const float x2) const {return (3.0*x1*x1-3.0*x2*x2)/(-9*x1*x1*x1*x1-18.0*x1*x1*x2*x2-9.0*x2*x2*x2*x2);}

	//xi+1
	__device__ float x1Next(const float x1, const float x2) const {return x1 - (jf11(x1, x2)*f1(x1, x2) + jf12(x1, x2)*f2(x1, x2));}
	__device__ float x2Next(const float x1, const float x2) const {return x2 - (jf21(x1, x2)*f1(x1, x2) + jf22(x1, x2)*f2(x1, x2));}


	// Ce système possède trois solutions
	__device__ float xa1() const {return 1.0;}
	__device__ float xa2() const {return 0.0;}

	__device__ float xb1() const {return -0.5;}
	__device__ float xb2() const {return sqrt(3.0)/2.0;}

	__device__ float xc1() const {return -0.5;}
	__device__ float xc2() const {return -sqrt(3.0)/2.0;}
    private:

	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/

    private:


	// Inputs
	int n;
	float epsilon;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
