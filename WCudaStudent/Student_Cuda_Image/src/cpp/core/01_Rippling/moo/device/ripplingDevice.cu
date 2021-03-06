#include <iostream>


#include "cudaTools.h"
#include "Device.h"
#include "Indice2D.h"
#include "RipplingMath.h"
#include "IndiceTools.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

__global__ void rippling(uchar4* ptrDevPixels, int w, int h, float t);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

__global__ void rippling(uchar4* ptrDevPixels, int w, int h, float t)
    {

    RipplingMath ripplingMath = RipplingMath(w,h); // ici pour preparer cuda
    const int WH = w * h;
    const int NB_THREAD=Indice2D::nbThread();
    const int TID=Indice2D::tid();

    int s=TID;

    int i;
    int j;
    while (s < WH)
	{
	IndiceTools::toIJ(s, w, &i, &j); // s[0,W*H[ --> i[0,H[ j[0,W[


	//ripplingMath.colorIJ(, i, j,t);
	ripplingMath.color(i,j,t,&ptrDevPixels[s]);

	s += NB_THREAD;
	}
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

