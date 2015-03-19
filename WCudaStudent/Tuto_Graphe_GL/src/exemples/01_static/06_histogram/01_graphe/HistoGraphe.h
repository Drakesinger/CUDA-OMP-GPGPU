#ifndef HISTO_GRAPHE_H_
#define HISTO_GRAPHE_H_

#include "Graph.h"
#include "Histogram.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * Objectif :
 *
 *	Histogramme d'un tableau de valeur
 *
 * Example:
 *
 * 	Gauss
 */
class HistoGraphe : public Graph
    {

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	HistoGraphe(float mean=10, float stdDev=10 ,int nbSeparation=200,int nbPoint=100000);

	virtual ~HistoGraphe();

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    private:

	    void createGraphe();
	    void createCurve();
	    void addCurve();

	/*--------------------------------------*\
	 |*		Attribut		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	int nbPoint;
	int nbSeparation;
	float mean;
	float stdDev;

	// Tools
	Histogram* ptrHisto;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
