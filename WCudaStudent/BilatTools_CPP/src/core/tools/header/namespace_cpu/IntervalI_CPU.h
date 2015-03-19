#ifndef INTERVAL_I_CPU_H_
#define INTERVAL_I_CPU_H_

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace cpu
    {
    class IntervalI
	{

	public:

	    IntervalI(int a, int b)
		{
		this->a = a;
		this->b = b;
		}

	public:

	    int getA(void)
		{
		return this->a;
		}

	    int getB(void)
		{
		return this->b;
		}

	public:

	    int a;
	    int b;
	};

    }
#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
