#ifndef DEVICE_H
#define DEVICE_H

#include "cuda_runtime.h"
#include <string>

using std::string;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/**
 * idDevice in [0,nbDevice-1]
 *
 * dim3.x
 * dim3.y
 * dim3.z
 *
 * sm=1.2 major=1 minor=2
 */
class Device
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/
    public:

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	/*--------------*\
	|* Wrapper      *|
	 \*-------------*/

	/**
	 * wrapper for cudaDeviceSynchronize()
	 */
	static void synchronize(void);

	/*--------------*\
	|* Tools      *|
	 \*-------------*/

	/**
	 * message = nameKernel by example
	 */
	static void checkKernelError(const char *message = NULL);

	/**
	 * Booth:
	 *    	assertDim(dg, db);
	 *	checkDimOPtimiser(dg, db);
	 */
	static void checkDimError(const dim3& dg, const dim3& db);

	static void checkDimOptimiser(const dim3& dg, const dim3& db);
	static void assertDim(const dim3& dg, const dim3& db);

	static int dim(const dim3& dim);
	static int nbThread(const dim3& dg, const dim3& db);

	static void print(const dim3& dg, const dim3& db);

	/*--------------*\
	|* 	get      *|
	 \*-------------*/

	static int getRuntimeVersion(void);
	static int getDriverVersion(void);

	static int getDeviceCount(void);
	static int getDeviceId(void);

	static cudaDeviceProp getDeviceProp(int idDevice);
	static cudaDeviceProp getDeviceProp(void);

	static string getNameSimple(int idDevice);
	static string getNameSimple(void);

	static string getName(int idDevice);
	static string getName(void);

	static dim3 getMaxGridDim(int idDevice);
	static dim3 getMaxGridDim(void);

	static dim3 getMaxBlockDim(int idDevice);
	static dim3 getMaxBlockDim(void);

	static int getWarpSize(int idDevice);
	static int getWarpSize(void);

	static int getMaxThreadPerBlock(int idDevice);
	static int getMaxThreadPerBlock(void);

	static int getMPCount(void);
	static int getMPCount(int idDevice);

	static int getCapacityMajor(int idDevice);
	static int getCapacityMajor(void);

	static int getCapacityMinor(int idDevice);
	static int getCapacityMinor(void);

	static int getAsyncEngineCount(int idDevice);
	static int getAsyncEngineCount(void);

	/*--------------*\
	|* print       *|
	 \*-------------*/

	static void printAll(void);
	static void printAllSimple(void);

	static void print(int idDevice);
	static void print(void);

	static void printCurrent(void);

	/*--------------*\
	 |*	Is       *|
	 \*-------------*/

	static bool isCuda(void);

	static bool isFermi(int idDevice);
	static bool isFermi(void);

	static bool isKepler(int idDevice);
	static bool isKepler(void);

	static bool isUVAEnable(int idDevice);
	static bool isUVAEnable(void);

	static bool isAtomicShareMemoryEnable(int idDevice);
	static bool isAtomicShareMemoryEnable(void);

	static bool isHostMapMemoryEnable(int idDevice);
	static bool isHostMapMemoryEnable(void);

	static bool isECCEnable(int idDevice);
	static bool isECCEnable(void);

	static bool isAsyncEngine(int idDevice);
	static bool isAsyncEngine(void);

	/*--------------*\
	|*	load     *|
	 \*-------------*/

	/**
	 * Force load
	 */
	static void loadCudaDriver(int deviceID, bool isMapMemoryEnable = true);
	/**
	 * Force load
	 */
	static void loadCudaDriver(bool isMapMemoryEnable = true);
	/**
	 * Force load
	 */
	static void loadCudaDriverAll(bool isMapMemoryEnable = true);

	/*--------------*\
	|*	p2p     *|
	 \*-------------*/

	/**
	 * use delete[] ptrMatrixP2PCompatibility after usage
	 * raw major vectoriser
	 */
	static int* p2pMatrixCompatibility(void);

	/**
	 * to be used after HANDLE_ERROR(cudaGLSetGLDevice(deviceId));
	 */
	static void p2pEnableALL(void);

	static void printP2PmatrixCompatibility(void);

	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/

    private:

    };

#endif

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

