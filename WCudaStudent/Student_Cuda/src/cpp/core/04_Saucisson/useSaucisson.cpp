#include <iostream>
#include <limits.h>
#include "saucissonSMHost.h"

using std::cout;
using std::endl;

bool useSaucisson(void)
    {
    cout << endl << "[SaucissonSM]" << endl;

    bool isOk = true;
    saucissonSMHost saucisson = saucissonSMHost(256);

    isOk&= saucisson.isOk();

    return isOk;
    }

