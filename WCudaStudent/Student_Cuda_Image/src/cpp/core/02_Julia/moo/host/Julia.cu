#include <iostream>
#include <assert.h>

#include "DomaineMath.h"
#include "Julia.h"
#include "Device.h"

using cpu::IntervalI;


using std::cout;
using std::endl;

extern __global__ void julia(uchar4* ptrDevPixels, int w, int h, DomaineMath ptrDomaineMathInit, int n, int nMax, float cx, float cy);

Julia::Julia(int w, int h, DomaineMath* domaineMath, int nMin, int nMax, float dt, float cx, float cy) :
	w(w),h(h),n(nMin),nMin(nMin),nMax(nMax),cx(cx),cy(cy),
	ptrDomaineMathInit(domaineMath),
	variateurAnimation(IntervalI(nMin, nMax), 1)
    {
// Tools
    this->dg = dim3(8, 8, 1);
    this->db = dim3(16, 16, 1);

// Outputs
    this->title = "Julia";
    }

Julia::~Julia()
    {
    // rien
    }

void Julia::animationStep()
    {
    this->n = variateurAnimation.varierAndGet();
    }

void Julia::process(uchar4* ptrDevPixels,int w, int h,const DomaineMath& domaineMath)
    {
    julia<<<dg,db>>>(ptrDevPixels, w, h, domaineMath, n, nMin, cx, cy);
    }

float Julia::getAnimationPara(void)
    {
    return variateurAnimation.get();
    }

DomaineMath* Julia::getDomaineMathInit(void)
{
return ptrDomaineMathInit;
}

float Julia::getT(void)
{
return n;
}

string Julia::getTitle(void)
{
return title;
}

int Julia::getW(void)
{
return w;
}

int Julia::getH(void)
{
return h;
}

