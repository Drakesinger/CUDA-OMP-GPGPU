#ifndef VARIATEUR_F_H_
#define VARIATEUR_F_H_

#include "IntervalF_CPU.h"

//using namespace cpu; //surtout pas de using namespace!! Si use dans partie gpu, il va y avoir conflit!

/**
 * F pour float
 */
class VariateurF
    {
    public:

	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

	VariateurF(const cpu::IntervalF& range, float dt);
	VariateurF();
	virtual ~VariateurF();


	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:

	double varierAndGet();
	double get();

	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Input
	float tMin;
	float tMax;
	float dt;

	// tools
	float t;
	bool isCroisssantPhase;

    };

#endif

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
