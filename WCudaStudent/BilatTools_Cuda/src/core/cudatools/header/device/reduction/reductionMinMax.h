#ifndef REDUCTION_MIN_MAX_H_
#define REDUCTION_MIN_MAX_H_

#ifndef MIN
#define MIN(X,Y) ((X)<(Y)?(X):(Y))
#endif

#ifndef MAX
#define MAX(X,Y) ((X)>(Y)?(X):(Y))
#endif


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported		*|
 \*-------------------------------------*/

#include "Indice1D.h"

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * Hyp
 * 	(H1) atomicMin existe pour T , sinon utiliser la version in reductionMinMaxLock.h
 * 	(H2) tabBlock size is a power of 2
 * 	(H3) tabBlock is already fill with data
 */
template <typename T>
__device__ void reduction_Min(T* tabBlock, T* ptrDevResultat);

/**
 * Hyp
 * 	(H1) atomicMax existe pour T , sinon utiliser la version in reductionMinMaxLock.h
 * 	(H2) tabBlock size is a power of 2
 * 	(H3) tabBlock is already fill with data
 */
template <typename T>
__device__ void reduction_Max(T* tabBlock, T* ptrDevResultat);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*-----------------*\
 |*	Intra      *|
 \*-----------------*/

template <typename T>
static __device__ void reduction_IntraBlock_Min(T* tabBlock);

template <typename T>
static __device__ void reduction_IntraBlock_Max(T* tabBlock);

/*-----------------*\
 |*	Inter      *|
 \*-----------------*/

template <typename T>
static __device__ void reduction_Interblock_Min(T* tabBlock, T* ptrDevResultat);

template <typename T>
static __device__ void reduction_Interblock_Max(T* tabBlock, T* ptrDevResultat);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/



/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

template <typename T>
__device__ void reduction_Min(T* tabBlock, T* ptrDevResultat)
    {
    reduction_IntraBlock_Min(tabBlock);

    __syncthreads();

    reduction_Interblock_Min(tabBlock, ptrDevResultat);
    }

template <typename T>
__device__ void reduction_Max(T* tabBlock, T* ptrDevResultat)
    {
    reduction_IntraBlock_Max(tabBlock);

    __syncthreads();

    reduction_Interblock_Max(tabBlock, ptrDevResultat);
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/



/*-----------------*\
 |*	Intra      *|
 \*-----------------*/


/**
 * Hyp :
 * 	(H1) 	length(tabBlock) est une puissance de 2 ! ie blockDim.x est une puissance de 2
 * 	(H2) 	gride et Block de dim 1
 * 	(H3) 	T est un type simple suppoter par atomicMin (sinon use reductionMinMaxLock.h)
 */
template <typename T>
__device__ void reduction_IntraBlock_Min(T* tabBlock)
    {
    // v1
//    int midle = blockDim.x / 2;
//    int tidLocal = threadIdx.x;
//
//    // int tidLocal =   Indice1D::tidLocal()
//
//    while (midle >= 1)
//	{
//
//	if (tidLocal < midle)
//	    {
//	    tabBlock[tidLocal] =MIN( tabBlock[tidLocal] ,tabBlock[tidLocal + midle]);
//	    }
//
//	__syncthreads(); // threads d'un meme block
//
//	//midle /= 2;
//	midle>>=1;
//	}

    //v2
        int midle = blockDim.x / 2;
        int tidLocal = threadIdx.x;

        //a 64 on ne divise plus et on a besoin de 32 thread pour finir de reduire le 64 premières cases
        while (midle >= 64)
    	{

    	if (tidLocal < midle)
    	    {
    	    tabBlock[tidLocal] =MIN( tabBlock[tidLocal], tabBlock[tidLocal + midle]);
}

    	__syncthreads();

    	//midle /= 2;
    	midle>>=1;
    	}

    // Utilisation des 32 thread d'un warp pour finir la reduction
        if(tidLocal<32)
    	{
    	// no __syncthreads() necessary after exah of the following lines as long as  we acces the data via a pointzer decalred as volatile
    	// because teh 32 therad in each warp execute in a locked-step with each other
    	volatile T* ptrData=tabBlock;

    	ptrData[tidLocal]=MIN( tabBlock[tidLocal], tabBlock[tidLocal + 32]);
ptrData[tidLocal]=MIN( tabBlock[tidLocal], tabBlock[tidLocal + 16]);
ptrData[tidLocal]=MIN( tabBlock[tidLocal], tabBlock[tidLocal + 8]);
ptrData[tidLocal]=MIN( tabBlock[tidLocal], tabBlock[tidLocal + 4]);
ptrData[tidLocal]=MIN( tabBlock[tidLocal], tabBlock[tidLocal + 2]);
ptrData[tidLocal]=MIN( tabBlock[tidLocal], tabBlock[tidLocal + 1]);
}
    }

/**
 * Hyp :
 * 	(H1) 	length(tabBlock) est une puissance de 2 ! ie blockDim.x est une puissance de 2
 * 	(H2) 	gride et Block de dim 1
 * 	(H3) 	T est un type simple suppoter par atomicMax  (sinon use reductionMinMaxLock.h)
 */
template <typename T>
__device__ void reduction_IntraBlock_Max(T* tabBlock)
    {
    //v1
//    int midle = blockDim.x / 2;
//    int tidLocal = threadIdx.x;
//
//    // int tidLocal =   Indice1D::tidLocal()
//
//    while (midle >= 1)
//	{
//
//	if (tidLocal < midle)
//	    {
//	    tabBlock[tidLocal] =MAX( tabBlock[tidLocal] ,tabBlock[tidLocal + midle]);
//	    }
//
//	__syncthreads(); // threads d'un meme block
//
//	midle /= 2;
//	}

    //v2
           int midle = blockDim.x / 2;
           int tidLocal = threadIdx.x;

           //a 64 on ne divise plus et on a besoin de 32 thread pour finir de reduire le 64 premières cases
           while (midle >= 64)
       	{

       	if (tidLocal < midle)
       	    {
       	    tabBlock[tidLocal] =MAX( tabBlock[tidLocal], tabBlock[tidLocal + midle]);
}

       	__syncthreads();

       	//midle /= 2;
       	midle>>=1;
       	}

       // Utilisation des 32 thread d'un warp pour finir la reduction
           if(tidLocal<32)
       	{
       	// no __syncthreads() necessary after exah of the following lines as long as  we acces the data via a pointzer decalred as volatile
       	// because teh 32 therad in each warp execute in a locked-step with each other
       	volatile float* ptrData=tabBlock;

       	ptrData[tidLocal]=MAX( tabBlock[tidLocal], tabBlock[tidLocal + 32]);
ptrData[tidLocal]=MAX( tabBlock[tidLocal], tabBlock[tidLocal + 16]);
ptrData[tidLocal]=MAX( tabBlock[tidLocal], tabBlock[tidLocal + 8]);
ptrData[tidLocal]=MAX( tabBlock[tidLocal], tabBlock[tidLocal + 4]);
ptrData[tidLocal]=MAX( tabBlock[tidLocal], tabBlock[tidLocal + 2]);
ptrData[tidLocal]=MAX( tabBlock[tidLocal], tabBlock[tidLocal + 1]);
}
}

/*-----------------*\
 |*	Inter      *|
 \*-----------------*/

/**
 * Hyp :
 * 	(H1) 	length(tabBlock) est une puissance de 2 ! ie blockDim.x est une puissance de 2
 * 	(H2) 	gride et Block de dim 1
 * 	(H3) 	T est un type simple suppoter par atomicMin
 * 	(H4)    ptrDevResultat a été initialisé avec une valeur intelligente
 */
template <typename T>
__device__ void reduction_Interblock_Min(T* tabBlock, T* ptrDevResultat)
{
if (threadIdx.x == 0)
{
atomicMin(ptrDevResultat, tabBlock[0]); // autant d'acces que de block
}
}

/**
 * Hyp :
 * 	(H1) 	length(tabBlock) est une puissance de 2 ! ie blockDim.x est une puissance de 2
 * 	(H2) 	gride et Block de dim 1
 * 	(H3) 	T est un type simple suppoter par atomicMax
 * 	(H4)    ptrDevResultat a été initialisé avec une valeur intelligente
 */
template <typename T>
__device__ void reduction_Interblock_Max(T* tabBlock, T* ptrDevResultat)
{
if (threadIdx.x == 0)
{
atomicMax(ptrDevResultat, tabBlock[0]); // autant d'acces que de block
}
}

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
