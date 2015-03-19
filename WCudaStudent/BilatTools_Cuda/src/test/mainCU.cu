#include <stdio.h>
#include <iostream>

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Importation 					*|
 \*---------------------------------------------------------------------*/

#include "cu.h"
#include "cu_cpp.h"

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
  |*		Imported		*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

bool mainCU(void);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static void lauchKernel(void);
static __global__ void kernelTest(void);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

bool mainCU(void)
    {
    cout << "[BilatTools_Cuda] : just inlcude to force compilation in .cu" << endl;

    lauchKernel();

    return true;
    }

void lauchKernel(void)
    {
    dim3 dg = dim3(1, 1, 1);
    dim3 db = dim3(1, 1, 1);

    kernelTest<<<dg,db>>>();
    Device::synchronize();
    }

__global__ void kernelTest(void)
    {
    printf("\nHello from kernel\n"); // TODO use classe
    }


/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

