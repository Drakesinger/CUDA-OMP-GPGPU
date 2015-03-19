#include <iostream>
#include <boost/thread.hpp>


using std::cout;
using std::endl;

using boost::thread;
using boost::chrono::milliseconds;
using boost::this_thread::sleep_for;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

void helloThread_ProcedureArgs(void);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static void runnable(float x);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

void helloThread_ProcedureArgs(void)
    {
    cout << "\nthread : procedure args : start" << endl;

    float x = 3.14;
   thread threadRunnable(runnable, x); // x sera passer à runnable

    cout << "Waiting for thread ..." << endl;

    threadRunnable.join();

    cout << "thread : procedure args : end" << endl;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

void runnable(float x)
    {
    cout << "runnable : start" << endl;
    cout << "x = " << x << endl;

    // Pretend to do something useful...
	{
	sleep_for(milliseconds(2000)); // from version 1.53 only
	}

    cout << "runnable: end" << endl;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

