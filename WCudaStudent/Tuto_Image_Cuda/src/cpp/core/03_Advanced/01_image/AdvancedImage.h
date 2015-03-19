#ifndef ADVANCED_IMAGE_H_
#define ADVANCED_IMAGE_H_

#include "Advanced.h"

#include "ImageFonctionel.h"
#include "SimpleKeyListener.h"
#include "SimpleMouseListener.h"
#include "Drawer2D.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class AdvancedImage: public ImageFonctionel
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	AdvancedImage(AnimableFonctionel_I* ptrAnimable);

	virtual ~AdvancedImage(void);

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:

	/*-----------------------*\
	|*      Override  	*|
	 \*----------------------*/

	/**
	 * Override, call periodicly by the api
	 */
	virtual void fillImageGL(uchar4* ptrTabPixels, int w, int h,const DomaineMath& domaineMath);

	/**
	 * Override, call periodicly by the api
	 */
	virtual void animationStep(bool& isNeedUpdateView);

	/**
	 * Override, call by the api at each "draw"
	 */
	virtual void paintPrimitives(Graphic2D& graphic2D);

    private:

	void listener(void);

	/*--------------------------------------*\
		|*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	AnimableFonctionel_I* ptrAnimable;

	// Tools
	SimpleKeyListener* ptrKeyListener;
	SimpleMouseListener* ptrMouseListener;
	Drawer2D* ptrDrawer2D;
    };

#endif

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
