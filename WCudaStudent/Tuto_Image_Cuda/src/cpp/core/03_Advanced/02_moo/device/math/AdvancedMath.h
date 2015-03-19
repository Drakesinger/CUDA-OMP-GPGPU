#ifndef ADVANCED_MATH_H_
#define ADVANCED_MATH_H_

#include "ColorTools.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * Dans un header only pour preparer la version cuda
 */
class AdvancedMath
    {
	/*--------------------------------------*\
	 |*		Constructeur		*|
	 \*-------------------------------------*/

    public:

	__device__
	AdvancedMath()
	    {
	    // rien
	    }

	__device__
	virtual ~AdvancedMath(void)
	    {
	    // rien
	    }

	/*--------------------------------------*\
	|*		Methode			*|
	 \*-------------------------------------*/

    public:

	__device__
	void colorXY(uchar4* ptrDevColor, int x, int y, float t)
	    {
	    uchar levelGris = 128;

	    ptrDevColor->x = levelGris;
	    ptrDevColor->x = levelGris;
	    ptrDevColor->x = levelGris;

	    ptrDevColor->w = 255; // opaque
	    }

    private:

	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    protected:

	// Inputs

	// Tools

    }
;

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
