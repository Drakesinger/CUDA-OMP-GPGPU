#include "VariateurF.h"
#include <assert.h>

using namespace cpu;

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
 |*		Public			*|
 \*-------------------------------------*/

VariateurF::VariateurF(const IntervalF& range, float dt)
    {
    this->dt = dt;
    this->tMin = range.a;
    this->tMax =range.b;

    // Tools
    this->isCroisssantPhase = true;
    this->t =range.a;

    assert(tMin<tMax);
    }

VariateurF::VariateurF()
    {
    //rien
    }

VariateurF::~VariateurF()
    {
    // rien
    }

double VariateurF::varierAndGet()
    {
    if (isCroisssantPhase)
	{
	if (t >= tMax)
	    {
	    isCroisssantPhase = false;
	    t -= dt;
	    }
	else
	    {
	    t += dt;
	    }
	}
    else
	{
	if (t <= tMin)
	    {
	    isCroisssantPhase = true;
	    t += dt;
	    }
	else
	    {
	    t -= dt;
	    }
	}

    return t;
    }

double VariateurF::get()
    {
    return t;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

