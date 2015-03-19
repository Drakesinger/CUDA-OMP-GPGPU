#include <iostream>

#include "SimpleKeyListener.h"

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

SimpleKeyListener::SimpleKeyListener()
    {
    //rien
    }

SimpleKeyListener::~SimpleKeyListener()
    {
    //rien
    }

/*-----------------------*\
|*	Methode  	*|
 \*----------------------*/

void SimpleKeyListener::onKeyPressed(const KeyEvent &event)
    {
    if (event.isSpecial())
	{
	cout << "Special Key Pressed " << event.getSpecialKey() << endl;
	}
    else
	{
	cout << "KeyPressed = " << event.getKey() << endl;
	}

    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

