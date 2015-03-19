#ifndef TESTDAMIER_H_
#define TESTDAMIER_H_

#include "cpptest.h"
#include "cudaType.h"
#include "cudaType_CPU.h"

#include "cudaTools.h" //for uchar4 of cuda

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class TestDamier : public Test::Suite
    {
	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	TestDamier();

	virtual ~TestDamier();

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	void testRVB();

	void testHSB();

	void testCustom();

    private :

	void fillImageCPU(cpu::uchar4* ptrTabPixel,int w,int h);

	void fillImageGPU(uchar4* ptrDevTabPixel,int w,int h);
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
