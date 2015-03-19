#include "LinesGraphe.h"
/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur		*|
 \*-------------------------------------*/

LinesGraphe::LinesGraphe()
    {
    createGraphe();
    createCurve();
    addCurve();
    }

LinesGraphe::~LinesGraphe()
    {
    delete ptrLineH;
    delete ptrSegmentA;
    delete ptrSegmentB;
    delete ptrSegmentC;
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

void LinesGraphe::createGraphe()
    {
    float x1 = 0;
    float x2 = 11;
    float y1 = -10;
    float y2 = 61;
    Domaine domaineGraph(x1, y1, x2, y2);
    setDomaine(domaineGraph);

    setTitle("Lines");
    }

void LinesGraphe::createCurve()
    {
    createSegmentA();
    createSegmentB();
    createSegmentC();
    createLigneHorizontal();
    createLigneVertical();
    }

void LinesGraphe::createLigneHorizontal()
    {
    Domaine* ptrDomaine = getDomaine();

    Color colorLine(255, 128, 0);
    Apparance apparanceLineH(colorLine);
    Title titleLineH("Horizontal line y=20");

    this->ptrLineH = new LineH(titleLineH, apparanceLineH, 20, ptrDomaine->getX1(), ptrDomaine->getX2());
    }

void LinesGraphe::createLigneVertical()
    {
    Domaine* ptrDomaine = getDomaine();

    Apparance apparanceLineV(Color::GREEN);
    Title titleLineV("Vertial Line x=2");

    this->ptrLineV = new LineV(titleLineV, apparanceLineV, 2, ptrDomaine->getY1(), ptrDomaine->getY2());
    }

void LinesGraphe::createSegmentA()
    {
    Apparance apparanceSegment(Color::BLUE);
    Title titleSegment("segmentA");

    Point p1(0, 60);
    Point p2(8, 60);

    this->ptrSegmentA = new Segment(titleSegment, apparanceSegment, p1, p2);
    }

void LinesGraphe::createSegmentB()
    {
    Apparance apparanceSegment(Color::RED);
    Title titleSegment("segmentB");

    Point p1(1, 45);
    Point p2(10, 61);

    this->ptrSegmentB = new Segment(titleSegment, apparanceSegment, p1, p2);
    }

void LinesGraphe::createSegmentC()
    {
    Apparance apparanceSegment(Color::YELLOW);
    Title titleSegment("segmentC");

    Point p1(3, -10);
    Point p2(5, 10);

    this->ptrSegmentC = new Segment(titleSegment, apparanceSegment, p1, p2);
    }

void LinesGraphe::addCurve()
    {
    add(ptrLineH);
    add(ptrLineV);
    add(ptrSegmentA);
    add(ptrSegmentB);
    add(ptrSegmentC);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
