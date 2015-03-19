#ifndef INDICE_1D
#define INDICE_1D

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class Indice1D
    {

	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:

	/*------------------*\
	|*	tid 	   *|
	 \*-----------------*/

	/**
	 * i in [0,nbThreadX-1]
	 * i=threadIdx.y + (blockDim.y * blockIdx.y)
	 */
	__device__
	static int tid()
	    {
	    return threadIdx.x + (blockDim.x * blockIdx.x);
	    }

	/**
	 * output in [0,nbThreadBlock()[
	 * return threadIdx;
	 */
	__device__
	static int tidLocalBlock()
	    {
	    return threadIdx.x;
	    }

	/**
	 * idem tidLocalBlock
	 */
	__device__
	static int tidBlock()
	    {
	    return threadIdx.x;
	    }

	/**
	 * idem tidLocalBlock
	 */
	__device__
	static int tidLocal()
	    {
	    return threadIdx.x;
	    }

	/*------------------*\
	|*	nbThread    *|
	 \*-------------------*/

	__device__
	static int nbThread()
	    {
	    return gridDim.x * blockDim.x;
	    }

	__device__
	static int nbThreadBlock()
	    {
	    return blockDim.x;
	    }

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
