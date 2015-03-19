#ifndef CAT_H_
#define CAT_H_

#include "Animals.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * @class Cat
 * @brief Represent the ensemble of Cats
 *
 * <pre>
 * Here you can write the full documentation of teh class Animal.
 * It's up to you!
 * </pre>
 *
 * http://en.wikipedia.org
 */
class Cat: public Animals
    {
    public:

	/**
	 * Create a Cat
	 * @param poids in kg
	 */
	Cat(int poids);

	/**
	 * Destructor
	 */
	virtual ~Cat();

	/**
	 * Override the virtual pure  methode eat of Animal
	 */
	void eat();

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
