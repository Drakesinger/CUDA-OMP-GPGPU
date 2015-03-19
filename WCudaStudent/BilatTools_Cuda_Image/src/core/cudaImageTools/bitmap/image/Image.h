#ifndef IMAGE_H_
#define IMAGE_H_

#include "Image_A.h"
#include "MathTools.h"
#include "ColorRGB_01.h"

#include "Animable_I.h"



/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class Image: public Image_A
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	\*-------------------------------------*/

    public:

	/**
	 * ptrColorRGB : color all titre
	 */
	Image(Animable_I* ptrAnimable, ColorRGB_01* ptrColorTitreRGB = new ColorRGB_01(1, 0, 0));

	/**
	 * Warning :delete ptrAnimable
	 */
	virtual ~Image(void);

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:

	void fillImageGL(uchar4* ptrDevImageGL, int w, int h); // override
	void animationStep(bool& isNeedUpdateView); // override
	void paintPrimitives(Graphic2D& graphic2D); // override

	/*--------------------------------------*\
	|*		Attributs		*|
	\*-------------------------------------*/

    private:

	// Input
	Animable_I* ptrAnimable;
	ColorRGB_01* ptrColorTitreRGB;
    };

#endif

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
