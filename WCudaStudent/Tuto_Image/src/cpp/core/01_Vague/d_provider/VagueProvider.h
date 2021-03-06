#ifndef VAGUE_PROVIDER_H_
#define VAGUE_PROVIDER_H_

#include "Image.h"
#include "Animable_I.h"


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class VagueProvider
    {
    public:

	static Image* createGL(void);
	static Animable_I* createMOO(void);

    };

#endif

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

