#include <iostream>
#include "Runnable.h"

#include <boost/thread.hpp>
#include <boost/date_time.hpp>



using std::cout;
using std::endl;

using boost::thread;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

void helloThread_Methode(void);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

void helloThread_Methode(void)
    {
    int x = 10;
    int y = 100;
    Runnable runnable(x, y);

    cout << "\nthread : methode : start" << endl;

    // arg1 : adresse de la methode run de la classe Runnable
    // arg2 : adresse de l'objet sur lequel aller chercher la metode run
   thread threadRunnable(&Runnable::run, &runnable);

    cout << "Waiting for thread ..." << endl;

    threadRunnable.join();
    cout << "thread : methode : end" << endl;

    cout << "[outside thread] : " << x << " + " << y << " = " << runnable.getResult() << endl; // give bad result cause runnable instance is passed by value to  boost::thread
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

