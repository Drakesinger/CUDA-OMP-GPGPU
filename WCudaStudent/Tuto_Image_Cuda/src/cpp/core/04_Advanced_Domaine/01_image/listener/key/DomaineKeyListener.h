#ifndef SIMPLE_KEY_LISTENER_H
#define SIMPLE_KEY_LISTENER_H

#include "KeyListener_I.h"
#include "DomaineMath.h"
#include "ImageFonctionel_A.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class DomaineKeyListener: public KeyListener_I
    {
    public:

	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

	DomaineKeyListener(ImageFonctionel_A* ptrImageFonctionel);

	virtual ~DomaineKeyListener();

    public:

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

	/**¨
	 * Override
	 */
	virtual void onKeyPressed(const KeyEvent& event);

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:
	// Inputs
	ImageFonctionel_A* ptrImageFonctionel;

	// Tools
	DomaineMath domaine1;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
