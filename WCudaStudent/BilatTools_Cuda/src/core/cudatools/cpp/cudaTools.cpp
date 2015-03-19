#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "cudaTools.h"
#include "StringTools.h"

using std::string;
using std::cout;
using std::cerr;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * Cuda
 */
void cudaHandleError(cudaError_t error, const char *file, int line)
    {
    if (error != cudaSuccess)
	{
	cerr << endl << "[CUDA ERROR] : " << cudaGetErrorString(error) << " in " << file << " at ligne " << line << endl;
	exit (EXIT_FAILURE);
	}
    }

/**
 * Curand
 */
void cudaHandleError(curandStatus_t statut, const char *file, int line)
    {
    if (statut != CURAND_STATUS_SUCCESS)
	{
	cerr << endl << "[CURAND ERROR] : " << statut << " in " << file << " at ligne " << line << endl;
	exit (EXIT_FAILURE);
	}
    }

/**
 * Cublas
 */
void cudaHandleError(cublasStatus_t cublasStatus, const char *file, int line)
    {

    if (cublasStatus != CUBLAS_STATUS_SUCCESS)
	{
	switch (cublasStatus)
	    {
	    case CUBLAS_STATUS_INVALID_VALUE:
		cerr << endl << "[CUBLAS ERROR] : CUBLAS_STATUS_INVALID_VALUE " << " in " << file << " at line " << line << endl;
		break;
	    case CUBLAS_STATUS_NOT_INITIALIZED:
		cerr << endl << "[CUBLAS ERROR] : CUBLAS_STATUS_NOT_INITIALIZED " << " in " << file << " at line " << line << endl;
		break;
	    case CUBLAS_STATUS_INTERNAL_ERROR:
		cerr << endl << "[CUBLAS ERROR] : CUBLAS_STATUS_INTERNAL_ERROR " << " in " << file << " at line " << line << endl;
		break;
	    case CUBLAS_STATUS_MAPPING_ERROR:
		cerr << endl << "[CUBLAS ERROR] : CUBLAS_STATUS_MAPPING_ERROR " << " in " << file << " at line " << line << endl;
		break;

	    case CUBLAS_STATUS_ALLOC_FAILED:
		cerr << endl << "[CUBLAS ERROR] : CUBLAS_STATUS_ALLOC_FAILED " << " in " << file << " at line " << line << endl;
		break;
	    case CUBLAS_STATUS_ARCH_MISMATCH:
		cerr << endl << "[CUBLAS ERROR] : CUBLAS_STATUS_ARCH_MISMATCH" << " in " << file << " at line " << line << endl;
		break;
	    case CUBLAS_STATUS_EXECUTION_FAILED:
		cerr << endl << "[CUBLAS ERROR] : CUBLAS_STATUS_EXECUTION_FAILED" << " in " << file << " at line " << line << endl;
		break;
	    default:
		cerr << endl << "[CUBLAS ERROR] : Unknown error !" << " in " << file << " at line " << line << endl;
		break;
	    }
	exit (EXIT_FAILURE);
	}
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

