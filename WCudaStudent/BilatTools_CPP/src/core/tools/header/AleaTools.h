#ifndef ALEATOOLS_H_
#define ALEATOOLS_H_

#include <cstdlib>
#include <time.h>

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/


/**
 * Not thread safe, see OpenpTools to obtian random number with parrallel thread
 */
class AleaTools
    {
    public:

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

	/**
	 * practice srand(time(NULL));
	 */
	AleaTools();

	/*--------------------------------------*\
	 |*		Destructor		*|
	 \*-------------------------------------*/

	virtual ~AleaTools();

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

	/**
	 * in [a,b]
	 * Attention : pas thread safe
	 */
	double uniformeAB(double a,double b);

	/**
	 * in [0,1]
	 * Attention : pas thread safe
	 */
	double uniforme01(void);

	/**
	 * in [a,b]
	 * Attention : pas thread safe
	 */
	int uniformeAB(int a,int b);


    private:

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/

    };

#endif


/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
