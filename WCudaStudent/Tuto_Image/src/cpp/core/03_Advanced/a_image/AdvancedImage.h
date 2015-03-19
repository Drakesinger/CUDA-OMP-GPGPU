#ifndef EVENT_IMAGE_H_
#define EVENT_IMAGE_H_

#include "Image_A.h"
#include "Animable_I.h"
#include "MathTools.h"
#include "SimpleKeyListener.h"
#include "SimpleMouseListener.h"
#include "Drawer2D.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class AdvancedImage: public Image_A
    {

	/*--------------------------------------*\
	 |*		Constructeur		*|
	 \*-------------------------------------*/

    public:

	AdvancedImage(Animable_I* ptrAnimable);
	virtual ~AdvancedImage(void);

	/*--------------------------------------*\
	 |*		Methode			*|
	 \*-------------------------------------*/

    protected:

	/*-----------------------*\
	|*      Override  	*|
	 \*----------------------*/

	/**
	 * Override, call periodicly by the api
	 */
	virtual void fillImageGL(uchar4* ptrTabPixels, int w, int h);

	/**
	 * Override, call periodicly by the api
	 */
	virtual void animationStep(bool& isNeedUpdateView);

	/**
	 * Override, call by the api at each "draw"
	 */
	virtual void paintPrimitives(Graphic2D& graphic2D);

    private:

	void control(void);

	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	Animable_I* ptrAnimable;

	// Tools
	SimpleKeyListener* ptrKeyListener;
	SimpleMouseListener* ptrMouseListener;
	Drawer2D* ptrDrawer2D;
    };

#endif

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 /*----------------------------------------------------------------------*/
