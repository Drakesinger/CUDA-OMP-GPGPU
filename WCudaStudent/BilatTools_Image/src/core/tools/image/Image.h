#ifndef _IMAGE_H_
#define _IMAGE_H_

#include "Image_A.h"
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
	|*		Constructeur		*|
	\*-------------------------------------*/

    public:

	Image(Animable_I* ptrAnimable);
	virtual ~Image(void);

	/*--------------------------------------*\
	|*		Methode			*|
	 \*-------------------------------------*/

    protected:


	/*----------------*\
	|*  Override	  *|
	 \*---------------*/

	/**
	 * Override, call periodicly by the api
	 */
	virtual void fillImageGL(uchar4* ptrDevImageGL, int w, int h);


	/**
	 * Override, call periodicly by the api
	 */
	virtual void animationStep(bool& isNeedUpdateView);

	/**
	 * Override, call periodicly by the api
	 */
	virtual void paintPrimitives(Graphic2D& graphic2D);

	/*--------------------------------------*\
	|*		Attribut		*|
	\*-------------------------------------*/

    private:

	// Tools
	Animable_I* ptrAnimable;

    };

#endif

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
