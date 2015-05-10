#include <iostream>
#include <limits.h>
#include "MathTools.h"

using std::cout;
using std::endl;

extern bool work(bool ,bool);

bool useBandwidth(void)
    {
    cout << endl << "[Bandwidth]" << endl;

    bool isOk = true;

    isOk &= work(true,true);

    return isOk;
    }
