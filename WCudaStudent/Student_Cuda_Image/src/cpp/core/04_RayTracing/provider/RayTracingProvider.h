#ifndef RAYTRACING_PROVIDER_H_
#define RAYTRACING_PROVIDER_H_

#include "RayTracing.h"
#include "Image.h"

class RayTracingProvider
    {
    public:

	static RayTracing* create(void);
	static Image* createGL(void);

    };

#endif
