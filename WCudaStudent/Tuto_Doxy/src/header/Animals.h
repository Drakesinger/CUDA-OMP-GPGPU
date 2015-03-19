#ifndef ANIMAL_H_
#define ANIMAL_H_

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * @class Animals
 * @brief Represent the ensemble of Animals
 *
 * <pre>
 * Here you can write the full documentation of teh class Animal.
 * It's up to you!
 * </pre>
 *
 * http://en.wikipedia.org
 */
class Animals
    {
    public:

	/**
	 * @param poids in kg
	 */
	Animals(int poids);

	/**
	 * Destructor exist in <b>C++</b>, we are not in java!
	 */
	virtual ~Animals();

	/**
	 * <pre>
	 * Virtual method to eat.
	 * Animal need to eat for live!
	 * </pre>
	 */
	virtual void eat()=0;

	/**
	 * Get the poids of the car
	 * @return weight in kg
	 */
	int getPoids();


    private:
	int poids; ///<en kg
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
