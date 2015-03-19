#ifndef IMAGE_FONCTIONEL_DOMAINE_H_
#define IMAGE_FONCTIONEL_DOMAINE_H_

#include "ImageFonctionel.h"
#include "DomaineKeyListener.h"
#include "DomaineListener.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class ImageFonctionelDomaine: public ImageFonctionel
    {

	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	ImageFonctionelDomaine(AnimableFonctionel_I* ptrAnimable);

	virtual ~ImageFonctionelDomaine();

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:

	virtual void paintPrimitives(Graphic2D& graphic2D); // override

    private :

	void controle();

	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/
    private:

	// Tools
	DomaineKeyListener* ptrKeyListener;
	DomaineListener* ptrDomaineListener;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
