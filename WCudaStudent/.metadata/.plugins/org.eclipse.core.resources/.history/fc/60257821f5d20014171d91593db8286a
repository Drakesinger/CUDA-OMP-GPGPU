#include "RayTracingProvider.h"
#include "MathTools.h"
#include <limits>

RayTracing* RayTracingProvider::create()
    {
    int dw = 16 * 80;
    int dh = 16 * 60;

    float dt = 0.01;

    return new RayTracing(dw, dh, dt);
    }

Image* RayTracingProvider::createGL(void)
    {
    ColorRGB_01* ptrColorTitre = new ColorRGB_01(255, 0, 128);
    return new Image(create(),ptrColorTitre);
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
