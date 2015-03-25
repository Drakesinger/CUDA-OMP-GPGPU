#ifndef RAYTRACING_PROVIDER_H_
#define RAYTRACING_PROVIDER_H_

#include "RayTracing.h"
#include "ImageFonctionel.h"

class RayTracingProvider
    {
    public:

	static RayTracing* create(void);
	static ImageFonctionel* createGL(void);
	__host__ Sphere* instanciateSpheres(Sphere*,int);
	__host__ void destructSpheres(Sphere*);
    };

#endif
