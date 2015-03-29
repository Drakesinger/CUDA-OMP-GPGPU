#ifndef RAYTRACINGSM_PROVIDER_H_
#define RAYTRACINGSM_PROVIDER_H_

#include "RayTracingSM.h"
#include "Image.h"

class RayTracingSMProvider
    {
    public:

	static RayTracingSM* create(void);
	static Image* createGL(void);

    };

#endif
