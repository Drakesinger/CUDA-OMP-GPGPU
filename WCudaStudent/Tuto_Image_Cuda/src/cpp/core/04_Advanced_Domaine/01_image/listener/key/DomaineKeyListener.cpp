#include <iostream>

#include "DomaineKeyListener.h"
#include "MathTools.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*-----------------------*\
|*	Constructor  	*|
 \*----------------------*/

DomaineKeyListener::DomaineKeyListener(ImageFonctionel_A* ptrImageFonctionel) :
	domaine1(PI / 2, PI / 2, 2 * PI, 2 * PI)
    {
    this->ptrImageFonctionel = ptrImageFonctionel;
    }

DomaineKeyListener::~DomaineKeyListener()
    {
    //rien
    }

/*-----------------------*\
|*	Methode  	*|
 \*----------------------*/

/**
 * Override
 *
 */
void DomaineKeyListener::onKeyPressed(const KeyEvent &event)
    {
    // Les domaines sont stocker dans une pile
    // goToDomaineInit pop tout jsuqu'à atteindre le premier element
    // goToPreviousDomaine pop le dernier élment
    // une pile est employer, pas un mememto
    cout<<"[DomaineKeyListener] : KeyPressed"<<endl;

    switch (event.getKey())
	{
	case '1' :
	    ptrImageFonctionel->goToDomaineInit();
	    break;
	case '2':
	    ptrImageFonctionel->goToPreviousDomaine();
	    break;
	case '3':
	    ptrImageFonctionel->setCurrentDomaine(domaine1);
	    break;
	}

    DomaineMath* ptrCurrentDomaine=ptrImageFonctionel->getCurrentDomaine();
    cout << "[DomaineKeyListener] :  Current Domaine is : "<< *ptrCurrentDomaine<<endl;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

