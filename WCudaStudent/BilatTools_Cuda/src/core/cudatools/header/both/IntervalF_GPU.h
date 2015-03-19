#ifndef INTERVAL_F_CUDA_H_
#define INTERVAL_F_CUDA_H_

#include "both_define.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace gpu
    {
    class IntervalF
	{

	    /*--------------------------------------*\
	|*		Constructeur		*|
	     \*-------------------------------------*/

	public:

	    __BOTH__
	    IntervalF(float a, float b)
		{
		this->a = a;
		this->b = b;
		}

	    // constructeur copie automatique car pas pointeur dans
	    //	IntervalF

//	    // TODO dangereux
//	    __device__  __host__
//	    IntervalF()
//		{
//
//		}

	    /*--------------------------------------*\
	|*		Methode			*|
	     \*-------------------------------------*/

	public:

	    __BOTH__
	    float getA(void)
		{
		return this->a;
		}

	    __BOTH__
	    float getB(void)
		{
		return this->b;
		}

	    /*--------------------------------------*\
	|*		Attribut		*|
	     \*-------------------------------------*/

	public:

	    float a;
	    float b;
	};

    }
#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
