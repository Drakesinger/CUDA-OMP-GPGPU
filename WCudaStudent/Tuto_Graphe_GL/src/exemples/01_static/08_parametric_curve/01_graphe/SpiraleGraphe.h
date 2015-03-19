#ifndef SPIRALE_GRAPH_H
#define SPIRALE_GRAPH_H

#include "Graph.h"
#include "SpiraleCurve.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * Objectif :
 *
 *	Afficher une courbe parametrique
 *
 * Exemple:
 *
 * 	Une spirale
 */
class SpiraleGraphe: public Graph
    {

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	SpiraleGraphe(int nbPoints = 1000);

	virtual ~SpiraleGraphe();

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

	// Input
	int nbPoints;

	// Tools
	SpiraleCurve* ptrSpiralCurve;

	float x0;
	float y0;
	int k;
	int m;

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
