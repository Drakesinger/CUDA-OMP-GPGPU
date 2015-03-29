#include "RayTracingSMProvider.h"
#include "MathTools.h"
#include <limits>

RayTracingSM* RayTracingSMProvider::create()
    {
    int dw = 300;
    int dh = 300;

    float dt = 0.01;

    return new RayTracingSM(dw, dh, dt);
    }

Image* RayTracingSMProvider::createGL(void)
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
