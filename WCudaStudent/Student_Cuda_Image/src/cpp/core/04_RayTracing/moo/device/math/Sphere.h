#ifndef SPHERE_H_
#define SPHERE_H_

#include "cudaTools.h"
#include <math.h>

#ifndef PI
#define PI 3.141592653589793f
#endif

class Sphere
    {
    public:
	__host__
	Sphere(float3 _center, float _radius, float _hue)
	    {
	    this->center = _center;
	    this->r = _radius;
	    this->rSquare = _radius* _radius;
	    this->hue = _hue;
	    this->T = 3.0 * PI/2.0;
	    }

	__host__
	Sphere(){}

	__device__ float hSquare(float2 xySol)
	    {
	    float a = center.x - xySol.x;
	    float b = center.y - xySol.y;
	    return a*a + b*b;
	    }

	__device__ bool isBelow(float hSquare)
	    {
	    return hSquare < rSquare;
	    }

	__device__ float dz(float hSquare)
	    {
	    return sqrtf(rSquare-hSquare);
	    }

	__device__ float brightness(float dz)
	    {
	    return dz/r;
	    }

	__device__ float distance(float dz)
	    {
	    return center.z-dz;
	    }

	__device__ float hueT(float t)
	    {
	    return 0.5 + 0.5*sin((float)(t + T +asin(2.0*hue-1.0)-T));
	    }

	__device__ float getHue()
	    {
	    return hue;
	    }
	float r;
	float3 center;
    private:
	float rSquare;
	float hue;
	float T;
    };


#endif 
