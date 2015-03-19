#ifndef VAGUE_MATH_H_
#define VAGUE_MATH_H_

#include "cudaType.h"
#include "MathTools.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * Dans un header only pour preparer la version cuda
 */
class VagueMath
    {

	/*--------------------------------------*\
	 |*		Constructeur		*|
	 \*-------------------------------------*/

    public:

	VagueMath(unsigned int w, unsigned int h)
	    {
	    this->factor = 4 * PI / (float) w;
	    }

	virtual ~VagueMath(void)
	    {
	    //rien
	    }

	/*--------------------------------------*\
	 |*		Methode			*|
	 \*-------------------------------------*/

    public:

	/**
	 * i in [0,h[
	 * j in [0,w[
	 * code commun à
	 * 	entrelacementOMP
	 * 	forAutoOMP
	 */
	void colorIJ(uchar4* ptrColorIJ, int i, int j, int t)
	    {
	    unsigned char levelGris;

	    f(levelGris,i, j, t); // update levelGris


	    ptrColorIJ->x = levelGris;
	    ptrColorIJ->y = levelGris;
	    ptrColorIJ->z = levelGris;

	    ptrColorIJ->w = 255; // opaque
	    }

    private:

	void f( unsigned char& levelGris,int i, int j, float t)
	    {
	    // example1
	    // levelGris = 255 * fabs(sin(t)); // same color for all the image (Hello image)

	    // Example2
	    levelGris = 255 * fabs(sin(i * factor + t));
	    }


	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	float factor;

    };

#endif

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 /*----------------------------------------------------------------------*/
