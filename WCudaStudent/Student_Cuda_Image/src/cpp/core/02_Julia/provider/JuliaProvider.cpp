#include "JuliaProvider.h"
#include "MathTools.h"
#include "DomaineMath.h"

Julia* JuliaProvider::create()
    {
    int dw = 300;
    int dh = 300;

    int nMin = 1;
    int nMax = 200;

    float dt = 0.1;
    DomaineMath *domaineMath = new DomaineMath(-1.3, -1.4, 1.3, 1.4);
    float cx = -0.12;
    float cy = 0.85;

    return new Julia(dw, dh, domaineMath, nMin, nMax, dt,cx,cy);
    }

ImageFonctionel* JuliaProvider::createGL(void)
    {
    ColorRGB_01* ptrColorTitre = new ColorRGB_01(0, 0, 0);
    return new ImageFonctionel(create(),ptrColorTitre);
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
