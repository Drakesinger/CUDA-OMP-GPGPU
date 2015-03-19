#include "HistoAdjustGraphe.h"
#include "GaussTools.h"

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur		*|
 \*-------------------------------------*/

HistoAdjustGraphe::HistoAdjustGraphe(float mean, float stdDev, int nbSeparation, int nbPoint)
    {
    this->nbPoint = nbPoint;
    this->nbSeparation = nbSeparation;
    this->mean = mean;
    this->stdDev = stdDev;

    createGraphe();
    createCurve();
    addCurve();

    update(); //To compute graph domaine!
    }

HistoAdjustGraphe::~HistoAdjustGraphe()
    {
    delete ptrHisto;
    delete ptrGaussCurve;
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

void HistoAdjustGraphe::createGraphe()
    {
    float x1 = mean - 30;
    float x2 = mean + 30;

    Interval intervalX(x1, x2);
    setIntervalX(intervalX); //IntervalY automatiquement calculé
    setTitle("Gauss");

    GridApparance* ptrGridApparance = getGridApparance();
    ptrGridApparance->setGrid(19, 11);
    }

void HistoAdjustGraphe::createCurve()
    {
    createDensity();
    createHisto();
    }

void HistoAdjustGraphe::createDensity()
    {
    Apparance apparanceGauss(Color::GREEN);
    Title titleGauss("Density");

    this->ptrGaussCurve = new GaussCurve(titleGauss, apparanceGauss, mean, stdDev);
    }

void HistoAdjustGraphe::createHisto()
    {
    shared_array<float> ptrTabValueX = GaussTools::generate(mean, stdDev, nbPoint);

    Apparance apparanceHisto(Color::RED);
    Title titleHisto("Histogram");
    int nbSeparation = 200;
    float maxDensity = ptrGaussCurve->getMaxDensity(); //afin de normaliser l'histogram avec la courbe de Gauss
    Interval intervalGraphX=getDomaine()->getIntervalX();

    this->ptrHisto = new HistogramToDensity(titleHisto, apparanceHisto, ptrTabValueX, nbPoint, intervalGraphX, nbSeparation, maxDensity);
    }

void HistoAdjustGraphe::addCurve()
    {
    add(ptrGaussCurve);
    add(ptrHisto);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

