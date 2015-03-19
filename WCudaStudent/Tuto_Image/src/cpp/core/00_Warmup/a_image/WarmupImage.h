#ifndef WARMUP_IMAGE_H_
#define VAGUE_IMAGE_H_

#include "Image_A.h"
#include "WarmupMOO.h"


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class WarmupImage: public Image_A
    {

	/*--------------------------------------*\
	 |*		Constructeur		*|
	 \*-------------------------------------*/

    public:

	WarmupImage(unsigned int w, unsigned int h, float dt);
	virtual ~WarmupImage(void);

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

	/*----------------*\
	|*  Private	  *|
	\*---------------*/

    private:


	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	string title;

	// Tools
	WarmupMOO* ptrWarmupMOO;
    };

#endif

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 /*----------------------------------------------------------------------*/
