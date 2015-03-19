#include <iostream>
#include <assert.h>

#include "DomaineMath.h"
#include "RayTracing.h"
#include "Device.h"

#include <math.h>
#include <limits>

#define BORD 200

using std::cout;
using std::endl;
using std::string;

extern __global__ void rayTracing(uchar4* ptrDevPixels, int w, int h, Sphere* ptrDevSpheres, DomaineMath domaineMath, const int NB_SPHERE, float t);

extern Sphere* instanciateSpheres(Sphere*,int);
extern void destructSpheres(Sphere*);

RayTracing::RayTracing(int w, int h, DomaineMath* domaineMath, const int NB_SPHERE, float dt):NB_SPHERE(NB_SPHERE)
    {
    // Inputs
    this->w = w;
    this->h = h;
    this->ptrDomaineMathInit = domaineMath;
    this->t = 0;
    this->dt = dt;

    // Tools
    this->dg = dim3(8, 8, 1);
    this->db = dim3(16, 16, 1);

    // Outputs
    this->title = "RayTracing";

    ptrSpheres = new Sphere[NB_SPHERE];

    for(int i = 0; i < NB_SPHERE; ++i)
	{
	float3 center;
	center.x = randomMinMax(BORD, w-BORD);
	center.y = randomMinMax(BORD, h-BORD);
	center.z = randomMinMax(10, 2*w);

	ptrSpheres[i] = Sphere(center, randomMinMax(20,80), randomMinMax(0, 1));
	}

    ptrDevSpheres = instanciateSpheres(ptrSpheres, NB_SPHERE);
    }

RayTracing::~RayTracing()
    {
    destructSpheres(ptrDevSpheres);
    delete[] ptrSpheres;
    }

/*-------------------------*\
 |*     Methode override    *|
 \*-------------------------*/

void RayTracing::process(uchar4* ptrDevPixels, int w, int h, const DomaineMath& domaineMath)
    {
    rayTracing<<<dg,db>>>(ptrDevPixels, w, h, ptrDevSpheres, domaineMath,NB_SPHERE ,t);
    }

float RayTracing::getAnimationPara(void)
    {
    return this->t;
    }

void RayTracing::animationStep()
    {
    this->t += dt;
    }

 /*--------------*\
 |* get override *|
 \*--------------*/
DomaineMath* RayTracing::getDomaineMathInit(void)
    {
    return ptrDomaineMathInit;
    }
float RayTracing::getT(void)
    {
    return t;
    }

string RayTracing::getTitle(void)
    {
    return title;
    }
int RayTracing::getW(void)
    {
    return w;
    }
int RayTracing::getH(void)
    {
    return h;
    }

float RayTracing::randomMinMax(float min, float max)
    {
    return (max-min)*((float)(rand())/(float)RAND_MAX) + min;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

