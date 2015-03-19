#ifndef INDICE_2D
#define INDICE_2D

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class Indice2D
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

	__device__
	static int tid()
	    {
	    return (threadIdx.x + (blockDim.x * blockIdx.x)) + ((threadIdx.y + (blockDim.y * blockIdx.y)) * (gridDim.x * blockDim.x));
	    }

    /**
     * output in [0,nbThreadBlock()[
     * return threadIdx.x+blockDim.x*threadIdx.y;
     */
    __device__
    static int tidLocalBlock()
	{
	return threadIdx.x + blockDim.x * threadIdx.y;
	}

    /**
     * idem tidLocalBlock
     */
    __device__
    static int tidBlock()
	{
	return threadIdx.x + blockDim.x * threadIdx.y;
	}

    /**
     * idem tidLocalBlock
     */
    __device__
    static int tidLocal()
	{
	return threadIdx.x + blockDim.x * threadIdx.y;
	}

    /*------------------*\
    |*	nbThread   	 *|
     \*-------------------*/

    __device__
    static int nbThread()
	{
	return (gridDim.x * gridDim.y) * (blockDim.x * blockDim.y);
	}

    __device__
    static int nbThreadX()
	{
	return gridDim.x * blockDim.x;
	}

    __device__
    static int nbThreadY()
	{
	return gridDim.y * blockDim.y;
	}

    __device__
    static int nbThreadBlock()
	{
	return blockDim.x * blockDim.y;
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
