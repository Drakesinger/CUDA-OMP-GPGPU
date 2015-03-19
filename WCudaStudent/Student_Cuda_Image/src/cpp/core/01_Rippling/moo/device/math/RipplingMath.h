#ifndef RIPPLING_MATH_H_
#define RIPPLING_MATH_H_

#include <math.h>

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class RipplingMath
    {

	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	__device__
	RipplingMath(int w, int h)
	    {
	    this->dim2 = w / 2;
	    }

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:

	/**
	 * x=pixelI
	 * y=pixelJ
	 */
	__device__
	void color(int i, int j, float t, uchar4* ptrColor)
	    {

		float result;
		dxy(i, j, &result);

		float color = 128 + 127 * (cos((result / 10.0f) - (t / 7.0f)) / ((result / 10.0f) + 1.0f));
		ptrColor->x = color;
		ptrColor->y = color;
		ptrColor->z = color;
		ptrColor->w = 255;

	    }

    private:
	__device__ void dxy(int i, int j, float *ptrResult) // par exmple
	    {
		float fx = i - this->dim2;
		float fy = j - this->dim2;
		*ptrResult = sqrt(fx * fx + fy * fy);
	    }
	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Tools
	double dim2; //=dim/2
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
