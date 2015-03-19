#ifndef DISCRET_SAMPLE_CURVE_GRAPHE_H_
#define DISCRET_SAMPLE_CURVE_GRAPHE_H_

#include "Graph.h"
#include "CurveDiscret.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * Objectif :
 *
 *	 Affiche une courbe en fonction d'un tableau de valeur yi
 *
 *	 Soit un tableau de valeurs tab de taille N alors :
 *
 *	 	f(x) = tab[x], x in [0,N-1]
 *
 */
class DiscretCurveGraph : public Graph
    {

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	DiscretCurveGraph();

	virtual ~DiscretCurveGraph();

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    private:

	void createGraphe();
	void createCurve();
	void addCurve();

	void createApparanceGraph();
	void createGridApparance();
	Apparance createApparanceCurve();

	void fillData(shared_array<float> ptrTabDataY);

	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

	// Tools
	int nbPoints;
	CurveDiscret* ptrCurveDis;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
