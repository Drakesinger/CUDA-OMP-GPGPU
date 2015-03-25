#include <iostream>

#include "Indice2D.h"
#include "cudaTools.h"
#include "Device.h"
#include "IndiceTools.h"
#include "DomaineMath.h"

#include "RayTracingMath.h"

using std::cout;
using std::endl;

__global__ void rayTracing(uchar4* ptrDevPixels, int w, int h, Sphere* ptrDevSpheres, DomaineMath domaineMath,int length, float t)
    {
    RayTracingMath rayTracingMath(ptrDevSpheres,length);

    int tid = Indice2D::tid();
    int nbThread = Indice2D::nbThread();
    const int MAX = w*h;

    int i,j;
    double x,y;
    int s = tid;
    while(s < MAX)
	{
	IndiceTools::toIJ(s,w,&i,&j);
	domaineMath.toXY(i,j,&x,&y);

	rayTracingMath.colorXY(x, y, t, &ptrDevPixels[s]);
	s += nbThread;
	}
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
