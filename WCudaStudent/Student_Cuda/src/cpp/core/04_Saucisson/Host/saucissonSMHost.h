#ifndef SAUCISSONSM_HOST_H_
#define SAUCISSONSM_HOST_H_

#include "cudaTools.h"
#include "MathTools.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class saucissonSMHost
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	saucissonSMHost(long n);
	bool isOk(void);
	virtual ~saucissonSMHost(void);

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	/*-------------------------*\
	|*   Override Animable_I   *|
	 \*------------------------*/

	/**
	 * Call periodicly by the api
	 */
	virtual void process(float* ptrSM, long n);

	/**
	 * Call periodicly by the api
	 */
	virtual string getTitle();

    private:

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	float* ptrDevPI;
	// Tools
	dim3 dg;
	dim3 db;
	float resultatEmp;
	float resultatThe;
	float PI;
	size_t sizeOctetPI;


	//Outputs
	//string title;
    };

#endif

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
