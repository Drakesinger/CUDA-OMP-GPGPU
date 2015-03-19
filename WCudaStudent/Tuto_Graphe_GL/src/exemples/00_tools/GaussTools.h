#ifndef GAUSS_TOOLS_H_
#define GAUSS_TOOLS_H_

#include <boost/random.hpp>
#include <boost/random/normal_distribution.hpp>

#include "shared_array.h"
//#include <boost/shared_array.hpp>
//using boost::shared_array;

static double PI = 3.1415926538979;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class GaussTools
    {

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	GaussTools()
	    {
	    //Nothing
	    }

	virtual ~GaussTools()
	    {
	    //Nothing
	    }

	/*--------------------------------------*\
	|*		Methode			*|
	 \*-------------------------------------*/

    public:

	static shared_array<float> generate(double mean, double stdDev, int n)
	    {
	    shared_array<float> ptrTabValue(new float[n]);

	    boost::mt19937* ptrRNG = new boost::mt19937();

	    // ptrRNG->seed(198765);
	    ptrRNG->seed(time(NULL));

	    boost::normal_distribution<> normal(mean, stdDev);
	    boost::variate_generator<boost::mt19937&, boost::normal_distribution<> > generator(*ptrRNG, normal);

	    for (int i = 0; i < n; i++)
		{
		ptrTabValue[i] =generator();
		}

	    return ptrTabValue;
	    }

	static double maxDensity(double mean, double stdDev)
	    {
	    return  1.0f / stdDev * sqrt(2 * PI);
	    }

	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
