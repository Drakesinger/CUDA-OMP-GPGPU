#include "PersonnageBD.h"


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur		*|
 \*-------------------------------------*/

/**
 * On prefix le tout avec le namespace bd
 * Il y a d'autres solutions, voir film,tele
 */

bd::Personnage::Personnage(string name,string inventeur):Invention(inventeur)
    {
    this->name=name;
    }

bd::Personnage::~Personnage()
    {
    //Nothing
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

string bd::Personnage::getName() const
    {
    return this->name;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

