#include <iostream>
#include <stdlib.h>
#include <assert.h>

#include "cudaTools.h"
#include "Device.h"
#include  "LimitsTools.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern int mainCore();
extern int mainTest();

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int main(void);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static void initCuda(int deviceId);
static int start(void);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int main(void)
    {
    cout << "main" << endl;

    // LimitsTools::rappelTypeSize();

    if (Device::isCuda())
	{
	 Device::printAll();
	Device::printAllSimple();

	// Server Cuda1: in [0,5]
	// Server Cuda2: in [0,2]
	int deviceId = 2;

	initCuda(deviceId);

	int isOk = start();

	//cudaDeviceReset causes the driver to clean up all state.
	// While not mandatory in normal operation, it is good practice.
	HANDLE_ERROR(cudaDeviceReset());

	return isOk;
	}
    else
	{
	return EXIT_FAILURE;
	}
    }

void initCuda(int deviceId)
    {
    // Check deviceId area
    int nbDevice = Device::getDeviceCount();
    assert(deviceId >= 0 && deviceId < nbDevice);

    //HANDLE_ERROR(cudaDeviceReset());

    // Choose current device (state of host-thread)
    HANDLE_ERROR(cudaSetDevice(deviceId));

    // It can be usefull to preload driver, by example to practice benchmarking! (sometimes slow under linux)
    Device::loadCudaDriver(deviceId);
    // Device::loadCudaDriverAll();// Force driver to be load for all GPU
    }

int start(void)
    {
    Device::printCurrent();

    bool IS_TEST = true;

    if (IS_TEST)
	{
	return mainTest();
	}
    else
	{
	return mainCore();
	}
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

