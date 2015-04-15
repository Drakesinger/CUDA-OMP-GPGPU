#ifndef HEATTRANSFERT_PROVIDER_H_
#define HEATTRANSFERT_PROVIDER_H_

#include "HeatTransfert.h"
#include "Image.h"

class HeatTransfertProvider
    {
    public:

	static HeatTransfert* create(void);
	static Image* createGL(void);

    };

#endif
