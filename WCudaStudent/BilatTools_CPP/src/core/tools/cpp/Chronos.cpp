#include <iostream>
#include <omp.h>
#include <stdio.h>
#include <string>

#include "Chronos.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructor		*|
 \*-------------------------------------*/

Chronos::Chronos()
    {
    start();
    }

Chronos::~Chronos()
    {
    // rien
    }

/*--------------------------------------*\
 |*		Methodes		*|
 \*-------------------------------------*/

void Chronos::start()
    {
   // cout << "Chronos : start" << endl;

    isRunning = true;

    deltaTime = -1;
    timeStart = time();
    }

double Chronos::stop()
    {
    //cout << "Chronos : stop" << endl;

    isRunning = false;

    timeStop = time();
    deltaTime = timeStop - timeStart;

    return deltaTime;
    }

double Chronos::getDeltaTime() const
    {
    if (isRunning)
	{
	cout << "Chronos : Warning : Stop chrono befor, or use methode timeFlight() instead!" << endl;
	return -1;
	}
    else
	{
	return deltaTime;
	}
    }

double Chronos::timeFlight() const
    {
    return time() - timeStart;
    }

void Chronos::print(const string& titre) const
    {
    print(cout, titre);
    }

void Chronos::print(ostream& stream, const string& titre) const
    {
    double dt;
    if (isRunning)
	{
	dt = timeFlight();
	}
    else
	{
	dt = deltaTime;
	}
    stream << titre << " " << dt << " (s)" << endl;
    }

double Chronos::time()
    {
   // return time(NULL); //  #include <time.h> time(NULL) est time_t
    // Problem : Sous linux : compte en seconde!

    return omp_get_wtime(); //#include <omp.h>
    }

/*--------------------------------------*\
 |*		Friend			*|
 \*-------------------------------------*/

ostream& operator <<(ostream& stream, const Chronos& chrono) // friend
    {
    chrono.print(stream);
    return stream;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

