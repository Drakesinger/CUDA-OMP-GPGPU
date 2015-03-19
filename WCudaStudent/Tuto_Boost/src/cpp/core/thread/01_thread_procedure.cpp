#include <iostream>
//#include <thread> // include with c++11 (#CXXFLAGS+= -std=c++0x)

using std::cout;
using std::endl;

#include <boost/thread.hpp>
#include <boost/date_time.hpp>

using boost::thread;
using boost::posix_time::seconds;
using boost::this_thread::sleep;
using boost::this_thread::get_id;


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

void helloThread_Procedure(void);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static void runnable(void);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

// http://antonym.org/2009/05/threading-with-boost---part-i-creating-threads.html

void helloThread_Procedure(void)
    {
    cout << "\nthread : procedure : start" << endl;

   thread threadRunnable(runnable);

    cout << "Waiting for thread ..." << endl;

    threadRunnable.join();

    cout << "thread : procedure : end " << endl;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

void runnable(void)
    {
    cout << "runnable : start" << endl;
    cout<<"Hello from thread : id  : "<<get_id() << endl;

    // Pretend to do something useful...
	{
	seconds workTime(3);
	sleep(workTime);
	}

    cout << "runnable: end" << endl;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

