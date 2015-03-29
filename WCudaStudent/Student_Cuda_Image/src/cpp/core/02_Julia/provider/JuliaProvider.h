#ifndef JULIA_PROVIDER_H_
#define JULIA_PROVIDER_H_

#include "Julia.h"
#include "ImageFonctionel.h"

class JuliaProvider
    {
    public:

	static Julia* create(void);
	static ImageFonctionel* createGL(void);

    };

#endif
