#include "PolylinesGraphe.h"
#include <math.h>

static double PI = 3.1415926538979;

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur		*|
 \*-------------------------------------*/

PolylinesGraphe::PolylinesGraphe(int nbPoint)
    {
    this->nbPoint = nbPoint;

    this->x0 = 5;
    this->y0 = 100;
    this->r = 10;

    createGraphe();
    createCurve();
    addCurve();
    }

PolylinesGraphe::~PolylinesGraphe()
    {
    delete ptrPolyline;
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

void PolylinesGraphe::createGraphe()
    {
    float x1 = x0 - 2 * r;
    float x2 = x0 + 2 * r;
    float y1 = y0 - 2 * r;
    float y2 = y0 + 2 * r;
    Domaine domaineGraph(x1, y1, x2, y2);
    setDomaine(domaineGraph);

    Color graphBackgroundColor = Color::WHITE;
    Color graphTitleColor = Color::BLACK;
    Apparance apparanceGraph(graphTitleColor, graphBackgroundColor);
    setApparance(apparanceGraph);

    setTitle("Polylines sample");
    }

void PolylinesGraphe::createCurve()
    {
    shared_array < Point > ptrTabPointXY(new Point[nbPoint]);
    fillTabPointXY (ptrTabPointXY);

    Title titlePolyline("Cercle");
    Color colorPolyline = Color::RED;
    Apparance apparancePolyline(colorPolyline);

    this->ptrPolyline = new Polylines(titlePolyline, apparancePolyline, ptrTabPointXY, nbPoint);
    }

void PolylinesGraphe::addCurve()
    {
    add(ptrPolyline);
    }

/**
 * Example, un cercle de centre (x0,y0) et de rayon r
 */
void PolylinesGraphe::fillTabPointXY(shared_array<Point> ptrTabPointXY)
    {
    // Pour fermer le cercle il faut revenir sur le point initial
    // Le dernier points est le même que le premier
    // Il y a nbPoints-1 segment, mais nbPoints

    double phi = 0;
    double dphi = 2 * PI / (nbPoint - 1);

    float xi, yi;
    for (int i = 0; i < nbPoint; i++)
	{
	xi = x0 + r * sin(phi);
	yi = y0 + r * cos(phi);

	Point pi(xi, yi);
	ptrTabPointXY[i] = pi;

	phi += dphi;
	}
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

