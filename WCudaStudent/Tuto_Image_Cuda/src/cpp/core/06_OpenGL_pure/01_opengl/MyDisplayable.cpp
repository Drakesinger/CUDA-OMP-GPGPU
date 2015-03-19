#include <iostream>
#include <GL/glew.h>

#include "MyDisplayable.h"

using std::cout;
using std::endl;

using cpu::IntervalF;


/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*----------------------*\
|*	Constructeur	*|
 \*---------------------*/

MyDisplayable::MyDisplayable():variateur(IntervalF(0 ,1), 0.01)
    {
    animationStep();
    }

MyDisplayable::~MyDisplayable()
    {
    // rien
    }

/*----------------------*\
|*	Methodes	*|
 \*---------------------*/

/*-----------*\
|* Override  *|
 \*----------*/

/**
 * Override
 */
void MyDisplayable::reshape(Panel_A &panel, int w, int h)
    {
    glViewport(0, 0, w, h);

    //Projection
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    double fovy = 45;
    if (h <= 0)
	{
	h = 1;
	}
    double ratio = w / h;

    gluPerspective(fovy, ratio, 1, 10);

    //Camera
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 3, 0, 0, 0, 0, 1, 0);
    }

/**
 * Override
 *
 * Animation:
 * 	Pour une animation, en fenetrage glut, il faut deriver de
 *
 * 		GLUTWindow
 *
 * 	Puis redéfinir IdlFunc, et faire un repaint dedans
 */
void MyDisplayable::display(Panel_A &panel)
    {
    glEnable (GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();

    animationStep();
    drawScene3D();

    glPopMatrix();
    glFinish();
    }

/**
 * Override
 */
void MyDisplayable::init(Panel_A &panel)
    {
    // Create OpenGL resources here (Textures,VBO,PBO,Shaders...)
    }

/**
 * Override
 */
void MyDisplayable::release(Panel_A &panel)
    {
    //Freen OpenGL resources here!
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

void MyDisplayable::drawScene3D()
    {
    glBegin (GL_TRIANGLES);

    glColor3f(1, 0, 0);
    glVertex3f(-1, -1, 0);
    glColor3f(0, 1, 0);
    glVertex3f(1, -1, 0);
    glColor3f(0, 0, 1);
    glVertex3f(0, py, 0);

    glEnd();
    }

void MyDisplayable::animationStep()
    {
    py=variateur.varierAndGet();

   // cout<<"[MyDisplayable] : py = "<<py<<endl;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

