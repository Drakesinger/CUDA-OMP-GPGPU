#include <iostream>
#include <math.h>
#include <cstdlib>
#include <stdlib.h>

#include "TabTools.h"
#include "AleaTools.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructor		*|
 \*-------------------------------------*/

TabTools::TabTools()
    {
    // rien
    }

TabTools::~TabTools()
    {
    // rien
    }

/*--------------------------------------*\
 |*		Methodes		*|
 \*-------------------------------------*/

/*----------------------*\
 |*	static		*|
 \*---------------------*/

 double TabTools::reduction(double* tab, int n)
    {
     double sum=0;
     for(int i=1;i<=n;i++)
    	{
    	sum+=*tab;
    	tab++;
    	}
     return sum;
    }

 void TabTools::init(double* tab,int n,double a)
    {
    for(int i=1;i<=n;i++)
	{
	*tab=a;
	tab++;
	}
    }




/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

