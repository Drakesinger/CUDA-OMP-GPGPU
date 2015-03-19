#ifndef IMAGE_FONCTIONEL_H_
#define IMAGE_FONCTIONEL_H_

#include "ImageFonctionel_A.h"
#include "MathTools.h"
#include "ColorRGB_01.h"

#include "AnimableFonctionel_I.h"



/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class ImageFonctionel: public ImageFonctionel_A
    {

	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	/**
	 * ptrColorRGB : color all titre
	 */
	ImageFonctionel(AnimableFonctionel_I* ptrAnimable, ColorRGB_01* ptrColorTitre = new ColorRGB_01(1, 0, 0));

	/**
	 * Warning : delete ptrAnimable et delete  ptrColorTitre
	 */
	virtual ~ImageFonctionel(void);

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:
	void fillImageGL(uchar4* ptrDevImageGL, int w, int h, const DomaineMath& domaineMath); // override
	void animationStep(bool& isNeedUpdateView); // override
	void paintPrimitives(Graphic2D& graphic2D); // override

	/*--------------------------------------*\
	|*		Attributs		*|
	\*-------------------------------------*/

    private:

	// Input
	AnimableFonctionel_I* ptrAnimable;
	ColorRGB_01* ptrColorTitreRGB;
    };

#endif

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
