#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "MathTools.h"


using std::cout;
using std::endl;

#ifndef MIN
#define MIN(a,b) (((a)<(b))?(a):(b))
#endif

#ifndef MAX
#define MAX(a,b) (((a)>(b))?(a):(b))
#endif

#ifndef ABS
#define ABS(x) ((x)>0?(x):-(x))
#endif

#ifndef MAXABS
#define MAXABS(a,b) (ABS((a))>ABS((b)) ? ABS((a)): ABS((b)))
#endif


/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructor		*|
 \*-------------------------------------*/

MathTools::MathTools()
    {
   // rien
    }

MathTools::~MathTools()
    {
    // rien
    }

/*--------------------------------------*\
 |*		Methodes static		*|
 \*-------------------------------------*/

/*----------------------*\
 |*	static		*|
 \*---------------------*/

/*---------------*\
|*	Float  	*|
\*---------------*/

bool MathTools::isEquals(float x1, float x2, float epsilon)
    {
    bool isOk;
    double delta;

    if (x1 == 0 || x2 == 0)
	{
	delta = fabs(x1 - x2);
	isOk = delta <= epsilon;
	}
    else
	{
	delta = fabs((x1 - x2) / MAXABS(x1,x2));
	isOk = delta <= epsilon;
	}

    if (!isOk)
	{
	cout << "isEgale Float: (x1,x2)=(" << x1 << "," << x2 << ") : delta (Relatif) = " << delta << endl;
	}

    return isOk;
    }


bool MathTools::isEquals(float a, float b, float reference, float epsilon)
    {
    return fabs((a - b) / reference) <= epsilon;
    }

bool MathTools::isEquals(float* tabA, float* tabB, int n, float epsilon)
    {
    for (int i = 0; i < n; i++)
	{
	if (!isEquals(tabA[i], tabB[i], epsilon))
	    {
	    return false;
	    }
	}
    return true;
    }

bool MathTools::isEqualsRelatifMax(float* tabA, float* tabB, int n, float epsilon)
    {
    float max = maxAbs(tabA, tabB, n);

    if (max != 0)
	{
	for (int i = 0; i < n; i++)
	    {
	    if (!isEquals(tabA[i], tabB[i], max, epsilon))
		{
		return false;
		}
	    }
	return true;
	}
    else
	{
	return true;// tous à zero
	//return isEquals(tabA, tabB, n, epsilon);
	}
    }

/*---------------*\
|*	Double  *|
\*---------------*/

bool MathTools::isEquals(double x1, double x2, double epsilon)
    {
    bool isOk;
    double delta;
    if (x1 == 0 || x2 == 0)
	{
	delta = fabs(x1 - x2);
	isOk = delta <= epsilon;
	}
    else
	{
	delta = fabs((x1 - x2) / MAXABS(x1,x2));
	isOk = delta <= epsilon;
	}

    if (!isOk)
	{
	cout << "isEgale Double : (x1,x2)=(" << x1 << "," << x2 << ") : delta (Relatif) = " << delta << endl;
	}

    return isOk;
    }

/*---------------*\
|*	Long  	*|
 \*---------------*/

bool MathTools::isEquals(long x1, long x2)
    {
    long delta = labs(x1 - x2);
    bool isOk = (delta == 0);

    if (!isOk)
	{
	cout << "isEgale Long: (x1,x2)=(" << x1 << "," << x2 << ") : delta (Relatif) = " << delta << endl;
	}

    return isOk;
    }

bool MathTools::isPower2(long i)
    {
    while (i >= 2)
	{
	if (i % 2 != 0)
	    {
	    return false;
	    }
	i /= 2;
	}
    return true;
    }

/*---------------*\
|*	isPower2  *|
\*---------------*/

bool MathTools::isPower2(int i) // TODO operateur bit
    {
    while (i >= 2)
	{
	if (i % 2 != 0)
	    {
	    return false;
	    }
	i /= 2;
	}
    return true;
    }

bool MathTools::isPower2(unsigned int i)  // TODO operateur bit
    {
    while (i >= 2)
	{
	if (i % 2 != 0)
	    {
	    return false;
	    }
	i /= 2;
	}
    return true;
    }

/*--------------------------------------*\
 |*	Methode static	private		*|
 \*-------------------------------------*/

float MathTools::maxAbs(float a, float b)
    {
    return MAXABS(fabs(a), fabs(b));
    }

float MathTools::maxAbs(float* tabA, float* tabB, int n)
    {
    float maxAbs = 0;

    for (int i = 0; i < n; i++)
	{
	if (fabs(tabA[i]) > maxAbs)
	    {
	    maxAbs = fabs(tabA[i]);
	    }
	if (fabs(tabB[i]) > maxAbs)
	    {
	    maxAbs = fabs(tabB[i]);
	    }
	}

    return maxAbs;
    }


/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

