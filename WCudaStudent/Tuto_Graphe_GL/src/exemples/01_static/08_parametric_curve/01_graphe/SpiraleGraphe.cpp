#include "SpiraleGraphe.h"

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur		*|
 \*-------------------------------------*/

SpiraleGraphe::SpiraleGraphe(int nbPoints)
    {
    this->nbPoints = nbPoints;

    this->x0 = 0.0f;
    this->y0 = 0.0f;
    this->k=4;
    this->m=4;
    this->nbPoints=nbPoints;

    createGraphe();
    createCurve();
    addCurve();
    }

SpiraleGraphe::~SpiraleGraphe()
    {
    delete ptrSpiralCurve;
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

void SpiraleGraphe::createGraphe()
    {
    float rMax=m*k;
    float x1 = x0 - 2*rMax;
    float x2 = x0 + 2*rMax;
    float y1 = y0 - 2*rMax;
    float y2 = y0 + 2*rMax;
    Domaine domaineGraph(x1, y1, x2, y2);
    setDomaine(domaineGraph);

    setTitle("Parametric Curve sample");
    }

void SpiraleGraphe::createCurve()
    {
    Title titleSpirale("Spirale");
    Color colorSpirale = Color::RED;
    Apparance apparanceSpirale(colorSpirale);

    this->ptrSpiralCurve = new SpiraleCurve(titleSpirale,apparanceSpirale,x0,y0,k,m,nbPoints);
    }

void SpiraleGraphe::addCurve()
    {
    add(ptrSpiralCurve);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

