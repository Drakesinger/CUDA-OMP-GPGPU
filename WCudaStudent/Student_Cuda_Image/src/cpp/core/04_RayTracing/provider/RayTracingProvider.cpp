#include "RayTracingProvider.h"
#include "MathTools.h"
#include "DomaineMath.h"
#include <limits>

RayTracing* RayTracingProvider::create()
    {
    int dw = 16 * 80;
    int dh = 16 * 60;

    const int NB_SPHERE = 50;
    float dt = 0.01;
    DomaineMath *domaineMath = new DomaineMath(0, 0, dw, dh);

    return new RayTracing(dw, dh, domaineMath, NB_SPHERE, dt);
    }

ImageFonctionel* RayTracingProvider::createGL(void)
    {
    ColorRGB_01* ptrColorTitre = new ColorRGB_01(255, 0, 128);
    return new ImageFonctionel(create(),ptrColorTitre);
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
