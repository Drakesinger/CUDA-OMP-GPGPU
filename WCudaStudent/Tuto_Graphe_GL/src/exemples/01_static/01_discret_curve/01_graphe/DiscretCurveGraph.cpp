#include "DiscretCurveGraph.h"

static int NB_POINTS = 10; //see fillData

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur		*|
 \*-------------------------------------*/

DiscretCurveGraph::DiscretCurveGraph()
    {
    nbPoints = NB_POINTS;

    createGraphe();
    createCurve();
    addCurve();
    }

DiscretCurveGraph::~DiscretCurveGraph()
    {
    delete ptrCurveDis;
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

/**
 * FontType possible :
 * 	BITMAP_13,
 * 	BITMAP_15,
 * 	TIMES_ROMAN_10,
 * 	TIMES_ROMAN_24,
 * 	HELVETICA_10,
 * 	HELVETICA_12,
 * 	HELVETICA_18
 */
void DiscretCurveGraph::createGraphe()
    {
    FontType font_type = TIMES_ROMAN_24; //Par defaut HELVETICA_12
    Title titleGraph("Discret Curve", font_type);
    setTitle(titleGraph);

    float x1 = 0;
    float x2 = nbPoints - 1;
    float y1 = -30; // valeur min du tableau
    float y2 = 100; // valeur max du tableau
    Domaine domaineGraph(x1, y1, x2, y2);
    setDomaine(domaineGraph);

    createApparanceGraph();
    createGridApparance();
    }

void DiscretCurveGraph::createCurve()
    {
    shared_array<float> tabValueY(new float[nbPoints]);
    fillData(tabValueY);

    FontType font_type = HELVETICA_12; //Par defaut
    Title title("Curve by TabValueY", font_type);

    Apparance apparanceCurve=createApparanceCurve();
    this->ptrCurveDis = new CurveDiscret(title, apparanceCurve, tabValueY, nbPoints);
    }

void DiscretCurveGraph::addCurve()
    {
    add(ptrCurveDis);
    }

/**
 * Example
 */
void DiscretCurveGraph::fillData(shared_array<float> ptrTabDataY)
    {
    float tabDataY[] =
	{
	-30, 54.6, 32.4, 96.1, 33.1, 54.3, 44.3, 22.4, 90.4, 100
	};

    for (int i = 1; i <= nbPoints; i++)
	{
	ptrTabDataY[i - 1] = tabDataY[i - 1];
	}
    }

/*--------------------------------------*\
 |*		Apparance		*|
 \*-------------------------------------*/

void DiscretCurveGraph::createApparanceGraph()
    {
    // Valeurs par defaut de l'apparance
    Color forground = Color::WHITE; // Couleur du titre
    Color background = Color::BLACK; //Couleur de l'arrière plan du graph
    TypeConnector connectorType = TYPE_LINES; //Pas pris en compte pour l'apparance du graph

    Apparance apparanceGraph(forground, background, connectorType);

    setApparance(apparanceGraph);
    }

void DiscretCurveGraph::createGridApparance()
    {
    // Valeurs par defaut de l'apprance de la grille
    int nbLignesX = 0; // 0 pas de lignes horizontal
    int nbLignesY = 0; // 0 pas de lignes vertical
    Color linesColor = Color::GRAY;

    GridApparance gridApparance(nbLignesX, nbLignesY, linesColor);

    setGridApparance(gridApparance);
    }

Apparance DiscretCurveGraph::createApparanceCurve()
    {
    Color forground = Color::RED; // Couleur de la courbe (ligne et la legend de la courbe)
    Color background = Color::BLACK; // Pas pris en compte
    TypeConnector connectorType = TYPE_LINES; //TYPE_LINES or TYPE_POINTS

    Apparance apparanceCurve(forground, background, connectorType);

    return apparanceCurve;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

