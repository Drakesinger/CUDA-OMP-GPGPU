#ifndef RAYTRACING_MATH_H_
#define RAYTRACING_MATH_H_

#include <math.h>
#include "ColorTools.h"
#include "float.h"
#include "Sphere.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class RayTracingMath
    {

	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	__device__ RayTracingMath(Sphere* spheres, int n):spheres(spheres),n(n)
	    {
	    }

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:
	__device__ void colorXY(float x, float y, float t, uchar4* ptrColor)
	    {
	    ptrColor->w = 255;

	    float min = FLT_MAX;
	    float hueMin = -FLT_MAX;
	    float brightnessMin = -FLT_MAX;

	    float2 xySol;
	    xySol.x = x;
	    xySol.y = y;

	    for(int i = 0; i < n; ++i)
		{
		Sphere sphere = spheres[i];
		float h2 = sphere.hSquare(xySol);

		if(sphere.isBelow(h2))
		    {

		    float dz = sphere.dz(h2);
		    float dist = sphere.distance(dz);

		    if(dist < min)
			{
			min = dist;
			hueMin = sphere.hueT(t);
			brightnessMin = sphere.brightness(dz);
			}
		    }
		}

	    if(hueMin >= 0 && brightnessMin >= 0)
		ColorTools::HSB_TO_RVB(hueMin, 1.0, brightnessMin, ptrColor);
	    else
		ptrColor->x = ptrColor->y = ptrColor->z = 0;
	    }

    private:
	Sphere* spheres;
	int n;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
