#ifndef BOTH_SMART_CBI_H_
#define BOTH_SMART_CBI_H_


/*----------------------------------------------------------------------*\
 |*		Pre-defined Compiler Macros			*|
 \*---------------------------------------------------------------------*/

// http://sourceforge.net/p/predef/wiki/Compilers/

// http://msdn.microsoft.com/en-us/library/b0084kay.aspx
// https://gcc.gnu.org/onlinedocs/cpp/Common-Predefined-Macros.html
// http://sourceforge.net/p/predef/wiki/Home/

// #ifdef __GNUC__
// #if defined(_MSC_VER)
// #ifdef __CBI_CUDA__

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

// Note
// 	Value of
//
//		__CUDACC__
//
//	is
//
//	   true 	for code in a 	.cu file, ie code compil with nvcc (host or device side)
//	   false 	for code in a   .cpp file, meme si nvcc est le compilateur used
//

// But:
//	Autoriser l'utilisation de code
//		__device__ __host__
//	sur le host, meme dans un fichier cpp

#ifdef __CUDACC__

#define __BOTH__  __device__ __host__
#define __HOST__  __host__

#else

// vide
#define __BOTH__
#define __HOST__

//# warning __BOTH__  --> empty
//# warning __HOST__  --> empty

#endif

// A tester
//#include "cuda_runtime.h"
//#include "code utilisant __host__.h"

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
