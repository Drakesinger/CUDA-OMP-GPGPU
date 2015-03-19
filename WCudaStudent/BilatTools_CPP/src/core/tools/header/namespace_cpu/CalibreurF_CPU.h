#ifndef CALIBREUR_F_CPU_H_
#define CALIBREUR_F_CPU_H_

#include "IntervalF_CPU.h"

namespace cpu
    {

    class CalibreurF
	{
	public:

	    /*--------------------------------------*\
	    |*		Constructor	      		*|
	     \*-------------------------------------*/

	    CalibreurF(const IntervalF& input, const IntervalF& output)
		{
		this->pente = (output.b - output.a) / (float) (input.b - input.a);
		this->translation = output.a - pente * input.a;
		}

	    /*--------------------------------------*\
	    |*		Methodes		*|
	     \*-------------------------------------*/

	public:

	    void calibrer(float& value)
		{
		value = value * pente + translation;
		}

	    float getPente()
		{
		return this->pente;
		}

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
