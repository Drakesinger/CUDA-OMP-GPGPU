#ifndef SIMPLE_MOUSE_LISTENER_H
#define SIMPLE_MOUSE_LISTENER_H

#include "MouseListener_I.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class SimpleMouseListener: public MouseListener_I
    {
    public:
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

	SimpleMouseListener();
	virtual ~SimpleMouseListener();

    public:

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

	void onMouseMoved(const MouseEvent& event); // override
	void onMousePressed(const MouseEvent& event); // override
	void onMouseReleased(const MouseEvent& event); // override
	void onMouseWheel(const MouseWheelEvent& event); // override

    private:

	void printXY(const MouseEvent& event);

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
