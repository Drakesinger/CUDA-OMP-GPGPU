#include "Drawer2D.h"
/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur		*|
 \*-------------------------------------*/

Drawer2D::Drawer2D(int w, int h) :
	w(w), h(h)
    {
    // Example : Version Objet
	{
	// Un rectangle
	    {
	    //(x,y) le coin supérieur gauche du rectangle
	    int x = w / 4;
	    int y = h / 4;
	    int wRect = w / 8;
	    int hRect = h / 8;

	    // Tools
	    this->ptrRect2D = new Rect2D(x, y, wRect, hRect);
	    }

	// Une ligne
	    {
	    int x1=0;
	    int y1=w/2;
	    int x2=w/3;
	    int y2=100;

	    this->ptrLine2D=new Line2D(x1,y1,x2,y2);
	    }

	// Un text2d
	    {
	    string textObjet="Text objet";
	    int x=100;
	    int y=100;

	    this->ptrText2D=new Text2D(x,y,textObjet);
	    }
	}
    }

Drawer2D::~Drawer2D()
    {
    delete ptrRect2D;
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

/**
 * Version non objet
 */
void Drawer2D::drawNonObjet(Graphic2D &graphic2D)
    {
    drawGreenRect(graphic2D);
    drawWiredRect(graphic2D);
    drawRedHorizontalLine(graphic2D);
    drawBlueVerticalLine(graphic2D);
    drawOrangeTexte(graphic2D);
    drawLineTriangle(graphic2D);
    drawTexteTopRight(graphic2D);
    }

/**
 * Version objet
 *
 * ptrRect2D est un attribut de la classe : instancier qu'une seule fois!
 */
void Drawer2D::drawObjet(Graphic2D &graphic2D)
    {
    // Rectangle
	{
	graphic2D.setColorRGB(0.6f, 0.8f, 0.5f);
	graphic2D.drawPrimitive(ptrRect2D);
	}

    // Ligne
	{
	graphic2D.setColorRGB(0.3f, 0.4f, 0.5f);
	graphic2D.drawPrimitive(ptrLine2D);

	}

    // text
	{
	graphic2D.setFont(TIMES_ROMAN_10);
	graphic2D.setColorRGB(1.0f, 1.0f, 1.0f);
	graphic2D.drawPrimitive(ptrText2D);
	}
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/**
 * Version non objet
 *
 * (x,y) le coin supérieur gauche du rectangle
 */
void Drawer2D::drawGreenRect(Graphic2D& graphic2D)
    {
    int x = w / 2;
    int y = h / 2;
    int wRect = w / 4;
    int hRect = h / 4;

    graphic2D.setColorRGB(0.0f, 1.0f, 0.0f, 1.0f);

    graphic2D.drawRect2D(x, y, wRect, hRect);
    }

/**
 * Version non objet
 *
 * (x,y) le coin supérieur gauche du rectangle
 */
void Drawer2D::drawWiredRect(Graphic2D& graphic2D)
    {
    int x = w / 2;
    int y = 30;
    int wRect = 100;
    int hRect = 50;

    graphic2D.setColorRGB(1.0f, 1.0f, 1.0f);

    graphic2D.drawWiredRect2D(x, y, wRect, hRect);
    }

/**
 * Version non objet
 *
 * List des polices possible :
 *
 * 	TIMES_ROMAN_10
 * 	TIMES_ROMAN_24
 * 	HELVETICA_10
 * 	HELVETICA_12
 * 	HELVETICA_18
 *	BITMAP_13
 *	BITMAP_15
 *
 * (x,y) coins inférieur gauche de la zone de texte
 */
void Drawer2D::drawOrangeTexte(Graphic2D& graphic2D)
    {
    int x = w / 4;
    int y = 3 * h / 4;

    graphic2D.setFont(TIMES_ROMAN_24);
    graphic2D.setColorRGB(1.0f, 0.5f, 0.0f);

    graphic2D.drawText(x, y, "Mon Texte");
    }

/**
 * Version non objet
 *
 * Ligne vertical défini (x,y),(x+l,y)
 */
void Drawer2D::drawRedHorizontalLine(Graphic2D& graphic2D)
    {
    int x = 0;
    int y = h / 2;
    int l = w;

    //graphic2D.setColorHSB(1,1,1);
    graphic2D.setColorRGB(1.0f, 0.0f, 0.0f);

    graphic2D.drawHorizontalLigne(x, y, l);
    }

/**
 * Version non objet
 *
 * Ligne vertical défini (x,y),(,y+l)
 */
void Drawer2D::drawBlueVerticalLine(Graphic2D& graphic2D)
    {
    int x = w / 2;
    int y = 0;
    int l = h;

    graphic2D.setColorRGB(0.0f, 0.0f, 1.0f);

    graphic2D.drawVerticalLigne(x, y, l);
    }

/**
 *  Version non objet
 *
 *  Dessine 3 ligne qui forme un triangle
 */
void Drawer2D::drawLineTriangle(Graphic2D& graphic2D)
    {
    int w = 150;
    int h = 80;
    int x = w / 4;
    int y = h / 4;

    graphic2D.setColorRGB(1.0f, 0.0f, 1.0f); 	//Maganta

    graphic2D.drawLigne(x, y + h, x + w, y); 	// hypothenus
    graphic2D.drawLigne(x, y, x, y + h); 	//opposite
    graphic2D.drawLigne(x, y, x + w, y); 	//adjacante
    }

/**
 * Version non objet
 *
 * List des polices possible :
 *
 * 	TIMES_ROMAN_10
 * 	TIMES_ROMAN_24
 * 	HELVETICA_10
 * 	HELVETICA_12
 * 	HELVETICA_18
 *	BITMAP_13
 *	BITMAP_15
 *
 * (x,y) coins inférieur gauche de la zone de texte
 */
void Drawer2D::drawTexteTopRight(Graphic2D& graphic2D)
    {
    graphic2D.setColorRGB(0.0f, 0.8f, 0.5f);
    graphic2D.setFont(TIMES_ROMAN_24);

    int x = w / 4;
    int y = 3 * h / 4;

    string texte = "Mon texte aligner a droite";
    int wTexte = graphic2D.texteWidth(texte);
    int hTexte = graphic2D.texteHeight(texte);

    graphic2D.drawText(w - wTexte, hTexte, texte);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

