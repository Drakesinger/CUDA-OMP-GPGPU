#include "Device.h"
#include <iostream>
#include "MathTools.h"
#include "cudaTools.h"

#define PI 3.14159265358979323846264338

extern __device__ void saucisson(float* ptrDevPI, long nsaucisson);

saucissonSMHost::saucissonSMHost(long n)
    {
	this->resultatEmp = 0;
    	this->resultatThe = PI;

    	this->dg = dim3(256, 1, 1);
	this->db = dim3(256, 1, 1);

	this->sizeOctetPI = sizeof(float);
	Device::assertDim(this->dg, this->db);

	HANDLE_ERROR(cudaMalloc(&ptrDevPI, sizeOctetPI));
	HANDLE_ERROR(cudaMemset(ptrDevPI,0,sizeOctetPI));
    }

void saucissonSMHost::~saucissonSMHost(void)
    {
	HANDLE_ERROR(cudaFree(ptrDevPI));
    }

saucissonSMHost::isOk()
    {
    return 0;
    }
/**
 * Override
 */
void saucissonSMHost::process()
    {
    saucisson<<<this->dg, this->db>>>(ptrDevPI, n);
    HANDLE_ERROR(cudaMemcpy(&PI,ptrDevPI, this->sizeOctetPI, cudaMemcpyDeviceToHost));
    }
