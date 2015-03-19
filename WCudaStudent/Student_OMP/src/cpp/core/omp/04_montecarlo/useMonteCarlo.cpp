#include <iostream>
#include <limits.h>

using std::cout;
using std::endl;
/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/
extern bool isMonteCarlo_promotiontab_Ok(int);
extern bool isMonteCarlo_sequentiel_Ok(int);
extern bool isMonteCarlo_entrelacer_atomic_Ok(int);
extern bool isMonteCarlo_for_atomic_Ok(int);

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

bool useMonteCarlo(void);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/
bool useMonteCarlo(void)
    {

    int n = INT_MAX/10;

    bool isOk = true;
    isOk &= isMonteCarlo_promotiontab_Ok(n);
    isOk &= isMonteCarlo_sequentiel_Ok(n);
    isOk &= isMonteCarlo_entrelacer_atomic_Ok(n);
    isOk &= isMonteCarlo_for_atomic_Ok(n);

    return isOk;
    }
/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

