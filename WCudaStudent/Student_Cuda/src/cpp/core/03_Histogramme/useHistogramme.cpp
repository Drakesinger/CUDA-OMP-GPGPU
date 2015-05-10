#include <iostream>
#include <limits.h>

using std::cout;
using std::endl;

extern bool histogrammeGM(int);

bool useHistogramme(void);

bool useHistogramme(void)
    {
    cout << endl << "[Histogramme]" << endl;

    bool isOk = true;

    isOk&= histogrammeGM(2560000);

    return isOk;
    }
