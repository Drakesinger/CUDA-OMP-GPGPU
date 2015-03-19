#include "NuagesPointsGraphe.h"
#include "UniformeTools.h"

#include <math.h>

static double PI = 3.1415926538979;

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur			*|
 \*-------------------------------------*/

NuagesPointsGraphe::NuagesPointsGraphe(int nbPoint)
    {
    this->nbPoints = nbPoint;

    this->x0 = -10;
    this->y0 = 40;
    this->rMin = 10;
    this->rMax = 20;

    createGraphe();
    createCurve();
    addCurve();

    //update(); //To compute graph domaine!
    }

NuagesPointsGraphe::~NuagesPointsGraphe()
    {
    delete ptrPolyline;
    }

/*--------------------------------------*\
 |*		Methodes		*|
 \*-------------------------------------*/

void NuagesPointsGraphe::createGraphe()
    {
    float x1 = x0 - 2 * rMax;
    float x2 = x0 + 2 * rMax;
    float y1 = y0 - 2 * rMax;
    float y2 = y0 + 2 * rMax;
    Domaine domaineGraph(x1, y1, x2, y2);
    setDomaine(domaineGraph);

    setTitle("Nuage Point");

    GridApparance* ptrGridApparance = getGridApparance();
    ptrGridApparance->setGrid(1, 1);
    }

void NuagesPointsGraphe::createCurve()
    {
    shared_array < Point > ptrTabPointXY = createTabPoint();

    Title titlePolyline("cercle corole");
    Color colorPolyline = Color::GREEN;

    Apparance apparancePolyline(colorPolyline);
    apparancePolyline.setConnectorType(TYPE_POINTS);

    this->ptrPolyline = new Polylines(titlePolyline, apparancePolyline, ptrTabPointXY, nbPoints);
    }

void NuagesPointsGraphe::addCurve()
    {
    add(ptrPolyline);
    }

/**
 * Example, un cercle de centre (x0,y0) et de rayon r
 */
shared_array<Point> NuagesPointsGraphe::createTabPoint()
    {
    shared_array < Point > ptrTabPointXY(new Point[nbPoints]);

    UniformTools uniformeTools;

    float xi, yi;
    for (int i = 0; i < nbPoints; i++)
	{
	double r = uniformeTools.generate(rMin, rMax);
	double phi = uniformeTools.generate(0, 2 * PI);

	xi = x0 + r * sin(phi);
	yi = y0 + r * cos(phi);

	Point pi(xi, yi);
	ptrTabPointXY[i] = pi;
	}

    return ptrTabPointXY;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

