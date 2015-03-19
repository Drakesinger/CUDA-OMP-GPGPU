#ifndef CALIBREUR_F_CUDA_H_
#define CALIBREUR_F_CUDA_H_

#include "both_define.h"
#include "IntervalF_GPU.h"

namespace gpu
    {

    class CalibreurF
	{
	public:

	    /*--------------------------------------*\
	|*		Constructor		*|
	     \*-------------------------------------*/

	    __BOTH__
	    CalibreurF(const IntervalF& input, const IntervalF& output)
		{
		this->pente = (output.b - output.a) / (input.b - input.a);
		this->translation = output.a - pente * input.a;
		}

	    // constructeur copie automatique car pas pointeur dans
		    //	CalibreurF
		    //	IntervalF

//	    // TODO dangereux
//	    __device__  __host__
//	    CalibreurF(const CalibreurF& source)
//		{
//		}



	    /*--------------------------------------*\
	|*		Methodes		*|
	     \*-------------------------------------*/

	public:

	    __BOTH__
	    void calibrer(float& value)
		{
		value = value * pente + translation;
		}

	    __BOTH__
	    float getPente()
		{
		return this->pente;
		}

	    __BOTH__
	    float getTranslation()
		{
		return this->translation;
		}

	    /*--------------------------------------*\
	|*		Attributs		*|
	     \*-------------------------------------*/

	private:

	    // Output
	    float pente;
	    float translation;

	};

    }
#endif

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
