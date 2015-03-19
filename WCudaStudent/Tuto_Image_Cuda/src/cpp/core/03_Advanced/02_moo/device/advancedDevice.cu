#include "Indice2D.h"
#include "IndiceTools.h"
#include "cudaTools.h"
#include "Device.h"
#include "DomaineMath.h"
#include "AdvancedMath.h"



/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

__global__ void advanced(uchar4* ptrDevPixels,int w, int h,DomaineMath domaineMath,float t);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

__global__ void advanced(uchar4* ptrDevPixels,int w, int h,DomaineMath domaineMath,float t)
    {
    AdvancedMath advancedMath;

    const int TID = Indice2D::tid();
    const int NB_THREAD = Indice2D::nbThread();

    const int WH=w*h;

    uchar4 color;

    double x;
    double y;

    int pixelI;
    int pixelJ;

    int s = TID;
    while (s < WH)
    	{
    	IndiceTools::toIJ(s, w, &pixelI, &pixelJ); // update (pixelI, pixelJ)

    	// (i,j) domaine ecran
    	// (x,y) domaine math
    	domaineMath.toXY(pixelI, pixelJ, &x, &y); //  (i,j) -> (x,y)

    	advancedMath.colorXY(&color,x, y,t); // update color

    	ptrDevPixels[s] = color;

    	s += NB_THREAD;
    	}
    }





/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

