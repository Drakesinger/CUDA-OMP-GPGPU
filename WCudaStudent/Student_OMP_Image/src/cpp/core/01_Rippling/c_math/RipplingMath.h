#ifndef RIPPLING_MATH_H_
#define RIPPLING_MATH_H_

#include "cudaType.h"
#include "MathTools.h"
#include "math.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * Dans un header only pour preparer la version cuda
 */
class RipplingMath
    {

	/*--------------------------------------*\
	|*		Constructeur		*|
	 \*-------------------------------------*/

    public:

	RipplingMath(unsigned int w, unsigned int h)
	    {
	    this->dim2 = w / 2;
	    }

	virtual ~RipplingMath(void)
	    {
	    //rien
	    }

	/*--------------------------------------*\
	|*		Methode			*|
	 \*-------------------------------------*/

    public:
	void colorIJ(uchar4* ptrColor, int i, int j, float t)
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

	void dxy(int i, int j, float *ptrResult) // par exmple
	    {
		float fx = i - this->dim2;
		float fy = j - this->dim2;
		*ptrResult = sqrt(fx * fx + fy * fy);
	    }

    private:

	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

	// Tools
	double dim2; //=dim/2

    };

#endif

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
