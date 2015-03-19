#ifndef SEQUENCE_VIEVER_CV_H_
#define SEQUENCE_VIEVER_CV_H_

#include <string>
#include "Capture_A.h"
#include "Chronos.h"


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class SequenceVieverCV
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	SequenceVieverCV(Capture_A* ptrCaptureur);
	virtual ~SequenceVieverCV(void);

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:

	void run();
	int fps(void);

private:

	int timeToWaitMS(Chronos* ptrChrono);

	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/

    private:

	//Inputs
	Capture_A* ptrCaptureur;

	// Tools
	bool isStart;

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
