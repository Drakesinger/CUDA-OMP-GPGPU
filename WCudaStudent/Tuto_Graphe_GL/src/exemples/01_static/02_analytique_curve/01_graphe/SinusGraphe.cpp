#include "SinusGraphe.h"
#include "SinusCurve.h"

#define PI 3.14159265

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constriucteur		*|
 \*-------------------------------------*/

SinusGraphe::SinusGraphe(float a)
    {
    this->a=a;

    createGraphe();
    createCurve();
    addCurve();
    }

SinusGraphe::~SinusGraphe()
    {
    delete ptrSinusCurve;
    }

/*--------------------------------------*\
 |*		Methodes		*|
 \*-------------------------------------*/

void SinusGraphe::createGraphe()
    {
    float x1 = 0;
    float x2 = 2 * PI;
    float y1 = -a;
    float y2 = a;
    Domaine domaineGraph(x1, y1, x2, y2);
    setDomaine(domaineGraph);

    setTitle("Analytique Curve");
    }

void SinusGraphe::createCurve()
    {
    Title titleSinus("sinus");
    Apparance apparanceSinus(Color::ORANGE);

    this->ptrSinusCurve=new SinusCurve(titleSinus, apparanceSinus, a);
    }

void SinusGraphe::addCurve()
    {
    add(ptrSinusCurve);
    }

/*-------------*\
 |*	get	*|
 \*------------*/

SinusCurve* SinusGraphe::getSinusCurve()
    {
    return ptrSinusCurve;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

