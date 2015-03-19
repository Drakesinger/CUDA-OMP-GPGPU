#include "HistoGraphe.h"
#include "GaussTools.h"

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

HistoGraphe::HistoGraphe(float mean, float stdDev,int nbSeparation,int nbPoint)
    {
    this->nbPoint=nbPoint;
    this->nbSeparation=nbSeparation;
    this->mean=mean;
    this->stdDev=stdDev;

    createGraphe();
    createCurve();
    addCurve();
    }

HistoGraphe::~HistoGraphe()
    {
    delete ptrHisto;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

void HistoGraphe::createGraphe()
    {
    float DX=40;

    float x1 = mean-DX;
    float x2 = mean+DX;
    setIntervalX(Interval(x1,x2));

    setTitle("Histogram");
    }

void HistoGraphe::createCurve()
    {
    shared_array<float> ptrTabValue=GaussTools::generate(mean,  stdDev,  nbPoint);

    Apparance apparanceHisto(Color::RED);
    Title titleHisto("Histogram from tabValue (Gauss)");

    Interval intervalGraphX=getDomaine()->getIntervalX();
    this->ptrHisto=new Histogram(titleHisto, apparanceHisto, ptrTabValue, nbPoint, intervalGraphX, nbSeparation);
    }

void HistoGraphe::addCurve()
    {
    add(ptrHisto);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

