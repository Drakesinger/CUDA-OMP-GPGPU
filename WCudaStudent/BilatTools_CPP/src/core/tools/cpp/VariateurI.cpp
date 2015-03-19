#include "VariateurI.h"
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

VariateurI::VariateurI(const IntervalI& range, int dt)
    {
    this->dt = dt;
    this->tMin = range.a;
    this->tMax = range.b;

    // Tools
    this->isCroisssantPhase = true;
    this->t =range.a;

    assert(tMin<tMax);
    }

VariateurI::VariateurI()
    {
    //rien
    }

VariateurI::~VariateurI()
    {
    // rien
    }

int VariateurI::varierAndGet()
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

int VariateurI::get()
    {
    return t;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

