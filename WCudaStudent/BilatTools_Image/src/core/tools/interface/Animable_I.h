#ifndef ANIMABLE_I_H_
#define ANIMABLE_I_H_

#include <iostream>
#include "cudaType.h"

using std::string;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class Animable_I
    {
    public:

	virtual void process(uchar4* ptrDevPixels,int w,int h)=0;
	virtual void animationStep(void)=0;

	virtual float getAnimationPara()=0;
	virtual string getTitle()=0;
	virtual int getW()=0;
	virtual int getH()=0;

    };

#endif

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

