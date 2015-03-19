#include <iostream>
#include <limits.h>

#include "LimitsTools.h"


using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructor		*|
 \*-------------------------------------*/

LimitsTools::LimitsTools()
    {
  // rien
    }

LimitsTools::~LimitsTools()
    {
    // rien
    }

/*--------------------------------------*\
 |*		Methodes		*|
 \*-------------------------------------*/

/*----------------------*\
 |*	static		*|
 \*---------------------*/


void LimitsTools::rappelTypeSize(void)
    {
    cout<<endl;
    cout<<"Rappel type size (from limits.h) "<<endl;
    cout<<"SHORT_MAX = "<<SHRT_MAX<<"      : "<<sizeof(short)<<" Octets"<<endl;
    cout<<"INT_MAX   = "<<INT_MAX<<" : "<<sizeof(int)<<" Octets"<<endl;
    cout<<"LONG_MAX  = "<<LONG_MAX<<" : "<<sizeof(long)<<" Octets"<<endl;
    cout<<endl;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

