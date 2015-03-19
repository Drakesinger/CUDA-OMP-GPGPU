#ifndef DOMAINE_LISTENER_H_
#define DOMAINE_LISTENER_H_

#include "DomaineMath.h"
#include "OnDomaineChangedListener.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class DomaineListener: public OnDomaineChangedListener
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	DomaineListener();

	virtual ~DomaineListener();

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	/**
	 * Override
	 */
	virtual void onDomaineChanged(DomaineMath* ptrDomaineMath);

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
