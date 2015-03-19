#ifndef _IMAGE_FONCTIONEL_H_
#define _IMAGE_FONCTIONEL_H_

#include "ImageFonctionel_A.h"
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
	|*		Constructeur		*|
	\*-------------------------------------*/

    public:

	ImageFonctionel(AnimableFonctionel_I* ptrAnimable);
	virtual ~ImageFonctionel(void);

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
	virtual void fillImageGL(uchar4* ptrDevImageGL, int w, int h,const DomaineMath& domaineMath);


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
	AnimableFonctionel_I* ptrAnimable;

    };

#endif

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
