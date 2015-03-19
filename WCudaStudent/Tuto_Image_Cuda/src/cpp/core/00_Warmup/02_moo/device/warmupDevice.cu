#include <iostream>
#include <stdlib.h>

#include "Indice2D.h"
#include "IndiceTools.h"
#include "cudaTools.h"


#include "WarmupMath.h"


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

__global__ void warmup(uchar4* ptrDevPixels,int w, int h,float t);


/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/



/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/


/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

__global__ void warmup(uchar4* ptrDevPixels, int w, int h, float t)
    {
    WarmupMath warmupMath = WarmupMath(w, h);

    const int TID = Indice2D::tid();
    const int NB_THREAD = Indice2D::nbThread();

    const int WH=w*h;

    uchar4 color;

    int pixelI;
    int pixelJ;

    int s = TID;
    while (s < WH)
	{
	IndiceTools::toIJ(s, w, &pixelI, &pixelJ); // update (pixelI, pixelJ)

	warmupMath.colorIJ(&color,pixelI, pixelJ, t); 	// update color
	ptrDevPixels[s] = color;

	s += NB_THREAD;
	}
    }


/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

