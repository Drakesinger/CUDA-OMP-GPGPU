#ifndef MY_PIXEL_COMPARATOR_H_
#define MY_PIXEL_COMPARATOR_H_

#include "PixelComparator_A.h"
#include "ColorTools_CPU.h"
#include <math.h>

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * PixelComparator_A is performed CPU side!
 */
class MyPixelComparator: public PixelComparator_A
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	virtual ~MyPixelComparator()
	    {
	    //Rien
	    }

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	/**
	 * Override
	 * Compute the hue difference between two pixel
	 */
	virtual float compare(cpu::uchar4 pixelA, cpu::uchar4 pixelB)
	    {
	    cpu::float3 hsbA;
	    cpu::float3 hsbB;

	    toHSB(pixelA, &hsbA);
	    toHSB(pixelB, &hsbB);

	    return fabsf(hsbA.x - hsbB.x); // hue est dans x
	    }

    private:

	void toHSB(cpu::uchar4 pixel, cpu::float3* ptrHSB)
	    {
	    cpu::ColorTools::RGB_TO_HSB(pixel.x, pixel.y, pixel.z, ptrHSB->x, ptrHSB->y, ptrHSB->z);
	    }

    };

#endif //MY_PIXEL_COMPARATOR_H_

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
