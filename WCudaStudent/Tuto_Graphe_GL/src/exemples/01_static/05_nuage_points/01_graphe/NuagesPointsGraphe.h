#ifndef NUAGE_POINTS_GRAPHE_H_
#define NUAGE_POINTS_GRAPHE_H_

#include "Graph.h"
#include "Polylines.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * Objectif :
 *
 * 	Afficher un nuage de point (xi,yi) sans relier les points.
 * 	(idem  polylines en ne dessinant que les points)
 *
 * Exemple:
 *
 * 	Corole
 */
class NuagesPointsGraphe: public Graph
    {

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	NuagesPointsGraphe(int nbPoints = 100000);

	virtual ~NuagesPointsGraphe();

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    private:

	void createGraphe();
	void createCurve();
	void addCurve();

	shared_array<Point> createTabPoint();

	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	int nbPoints;

	// Tools
	Polylines* ptrPolyline;
	float x0;
	float y0;
	float rMin;
	float rMax;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
