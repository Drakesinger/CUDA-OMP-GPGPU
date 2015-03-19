#include "../04_montecarlo/monteCarlotools.h"

#include <iostream>
#include "Chronos.h"
#include "MathTools.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

bool isAlgo_OK(AlgoMonteCarlo algoPI, int n, string title)
    {
    cout << endl << "[" << title << " running ...]" << endl;
    cout << "n=" << n << endl;

    Chronos chrono;
    double piHat = algoPI(n);
    chrono.stop();

    cout.precision(8);
    cout << "Pi hat  = " << piHat << endl;
    cout << "Pi true = " << PI << endl;

    bool isOk = MathTools::isEquals(piHat, PI, 1e-6);
    cout << "isOk = " << isOk << endl;

    cout.precision(3);
    chrono.print("time : ");

    return isOk;
    }

double f_montecarlo(double x){
    return 1 / (1 + x * x);
}
/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

