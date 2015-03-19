#ifndef LINES_GRAPHE_H_
#define LINES_GRAPHE_H_

#include "Graph.h"
#include "Segment.h"
#include "LineH.h"
#include "LineV.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * Objectif :
 *
 *	Dessiner des segments et des lignes horizontale et vertical.
 *
 *	Une ligne vertical en x=2 en vert
 *	Une ligne horizontal en y=20 en orange
 *	Un segment A bleu
 *	Un segment B rouge
 *	Un segment C cyan
 *
 */
class LinesGraphe : public Graph
    {

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	LinesGraphe();

	virtual ~LinesGraphe();

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    private:

	void createGraphe();
	void createCurve();
	void addCurve();


	void createLigneHorizontal();
	void createLigneVertical();
	void createSegmentA();
	void createSegmentB();
	void createSegmentC();

	/*--------------------------------------*\
	 |*		Attribut		*|
	 \*-------------------------------------*/

    private:

	// Tools
	Segment* ptrSegmentA;
	Segment* ptrSegmentB;
	Segment* ptrSegmentC;
	LineH* ptrLineH;
	LineV* ptrLineV;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
