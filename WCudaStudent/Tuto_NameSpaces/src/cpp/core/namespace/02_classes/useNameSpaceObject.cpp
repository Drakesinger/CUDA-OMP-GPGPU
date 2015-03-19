#include "PersonnageBD.h"
#include "PersonnageFilm.h"
#include "PersonnageTele.h"

#include <iostream>
using std::cout;
using std::endl;



/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/



/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * Dans les trois namespace:
 * 	bd
 * 	film
 * 	tele
 *
 * La classe est la meme, ie Personnage!
 * Le namespace permet d'éviter des conflits de nom.
 *
 * Attention:
 * 	Contrairement à java, le nom des fichiers (.cpp, .h) ne peut lui être trois fois le meme.
 * 	Il doit etre obligatoirement etre different:
 *
 * 		PersonnageBD.h PersonnageBD.cpp
 * 		PersonnageFilm PersonnageFilm
 * 		PersonnageTele PersonnageTele
 *
 */
void useNameSpaceObject()
    {
    cout<< endl<<"[Using Namespaces with Object] :"<<endl<<endl;

    bd::Personnage tintin("Tintin (BD)","Herge");
    film::Personnage jack("Jack Gruger (FILM)");
    tele::Personnage drucker("Drucker (TELE)");

    cout<<"Personnage de bd = "<<tintin.getName()<<endl;
    cout<<"Personnage de film = "<<jack.getName()<<endl;
    cout<<"Personnage de tele = "<<drucker.getName()<<endl;

    cout<<"Tintin inventeur"<<tintin.getInventeur()<<endl;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

