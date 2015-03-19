#ifndef RUNNABLE_H_
#define RUNNABLE_H_

#include <iostream>
#include <boost/date_time.hpp>
#include <boost/thread.hpp>

using std::cout;
using std::endl;

using boost::posix_time::seconds;
using boost::this_thread::sleep;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class Runnable
    {
    public:

	Runnable(int a, int b)
	    {
	    // inputs
	    this->a = a;
	    this->b = b;

	    // ouputs
	    this->result = -1;
	    }

	virtual ~Runnable(void)
	    {
	    // rien
	    }

	/**
	 * Foncteur
	 */
	void operator()()
	    {
	    cout << "runnable : foncteur : start" << endl;
	    work();
	    cout << "runnable : foncteur : end" << endl;
	    }

	void run(void)
	    {
	    cout << "runnable : methode : start" << endl;
	    work();
	    cout << "runnable : methode : end" << endl;
	    }

	int getResult(void)
	    {
	    return this->result;
	    }

    private:

	/**
	 * common to work and operator()
	 */
	void work(void)
	    {

	    this->result = a + b;
	    cout << "[inside thread] : " << a << " + " << b << " = " << result << endl;
	    // Pretend to do something useful...
		{
		seconds workTime(3);
		sleep(workTime);
		}
	    }

    private:

	int a;
	int b;
	int result;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
