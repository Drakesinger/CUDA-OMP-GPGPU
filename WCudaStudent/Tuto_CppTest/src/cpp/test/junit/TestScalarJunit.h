#ifndef TEST_SCALAR_JUNIT_H
#define TEST_SCALAR_JUNIT_H

#include "cpptest.h"
#include "scalar.h"



class TestScalarJunit: public Test::Suite
    {
    public:

	TestScalarJunit(void)
	    {
	    TEST_ADD(TestScalarJunit::testAdd);
	    TEST_ADD(TestScalarJunit::testFois);
	    }

    private:

	void testAdd(void)
	    {
	    TEST_ASSERT(sum(2,3)==5);
	    TEST_ASSERT(sum(-2,3)==1.0);
	    }

	void testFois(void)
	    {
	    TEST_ASSERT(fois(2,3)==6);
	    TEST_ASSERT(fois(-2,3)==-6);
	    }
    };

#endif

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/


