#include "TestDamier.h"
#include "DamierProvider.h"
#include "ComparatorImageHSB.h"
#include "ComparatorImageRVBA.h"
#include "MyPixelComparator.h"

#include <iostream>
using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur		*|
 \*-------------------------------------*/

TestDamier::TestDamier()
    {
    TEST_ADD(TestDamier::testRVB);
    TEST_ADD(TestDamier::testHSB);
    TEST_ADD(TestDamier::testCustom);
    }

TestDamier::~TestDamier()
    {
    // Rien
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

void TestDamier::testRVB()
    {
    // dimension
    int w = 1024; //Disons
    int h = 768;  //Disons
    size_t size = w * h * sizeof(uchar4);

    // Allocation memoires
    cpu::uchar4* ptrImageSrc = new cpu::uchar4[w * h]; //Host
    cpu::uchar4* ptrImageHat = new cpu::uchar4[w * h]; //Host
    uchar4* ptrDevImageHat = NULL; //Devie
    HANDLE_ERROR(cudaMalloc(&ptrDevImageHat, size));

    // Remplissage
	{
	fillImageCPU(ptrImageSrc, w, h);
	fillImageGPU(ptrDevImageHat, w, h);
	HANDLE_ERROR(cudaMemcpy(ptrImageHat, ptrDevImageHat, size, cudaMemcpyDeviceToHost));
	}

    // Comparaison, host side
	{
	int epsilonRVB = 1; //1 car en RVBA la difference min est de 1! uchar in [0,255]
	ComparatorImageRVBA comparatorRVBA(ptrImageSrc, ptrImageHat, w, h);
	ComparatorImageResult result = comparatorRVBA.run(epsilonRVB);

	TEST_ASSERT(result.isEgal);

	//cout << " #error 	= " << result.nbErreur << endl;
	//cout << " deltaMax	= " << result.deltaMax << endl;
	//cout << " deltaMin	= " << result.deltaMin << endl;
	}

    // Liberation memoires
	{
	HANDLE_ERROR(cudaFree(ptrDevImageHat));
	delete[] ptrImageSrc;
	delete[] ptrImageHat;
	}
    }

void TestDamier::testHSB()
    {
    // dimension
    int w = 1024; //Disons
    int h = 768;  //Disons
    size_t size = w * h * sizeof(uchar4);

    // Allocation memoires
    cpu::uchar4* ptrDamierSrc = new cpu::uchar4[w * h]; //Host
    cpu::uchar4* ptrDamierHat = new cpu::uchar4[w * h]; //Host
    uchar4* ptrDevDamierHat = NULL; //Devie
    HANDLE_ERROR(cudaMalloc(&ptrDevDamierHat, size));

    // Remplissage
	{
	fillImageCPU(ptrDamierSrc, w, h);
	fillImageGPU(ptrDevDamierHat, w, h);
	cudaMemcpy(ptrDamierHat, ptrDevDamierHat, size, cudaMemcpyDeviceToHost);
	}

    // Comparaison
	{
	float epsilonHSB = 1e-5; // epsilon in [0,1[ car HSB in [0,1]!

	ComparatorImageHSB comparatorHSB(ptrDamierSrc, ptrDamierHat, w, h);
	ComparatorImageResult result = comparatorHSB.run(epsilonHSB);

	TEST_ASSERT(result.isEgal);

	//cout << " #error 	= " << result.nbErreur << endl;
	//cout << " deltaMax	= " << result.deltaMax << endl;
	//cout << " deltaMin	= " << result.deltaMin << endl;
	}

    // Liberation memoires
	{
	HANDLE_ERROR(cudaFree(ptrDevDamierHat));
	delete[] ptrDamierSrc;
	delete[] ptrDamierHat;
	}
    }

void TestDamier::testCustom()
    {
    // dimension
    int w = 1024; //Disons
    int h = 768;  //Disons
    size_t size = w * h * sizeof(uchar4);

    // Allocation memoires
    cpu::uchar4* ptrDamierSrc = new cpu::uchar4[w * h]; //Host
    cpu::uchar4* ptrDamierHat = new cpu::uchar4[w * h]; //Host
    uchar4* ptrDevDamierHat = NULL; //Devie
    HANDLE_ERROR(cudaMalloc(&ptrDevDamierHat, size));

    // Remplissage
	{
	fillImageCPU(ptrDamierSrc, w, h);
	fillImageGPU(ptrDevDamierHat, w, h);
	HANDLE_ERROR(cudaMemcpy(ptrDamierHat, ptrDevDamierHat, size, cudaMemcpyDeviceToHost));
	}

    // Comparaison
	{
	float epsilonCustom = 1e-5; // epsilon in [0,1[ car Hue in [0,1]!

	MyPixelComparator pixelComparator;
	ComparatorImage comparatorCustom(ptrDamierSrc, ptrDamierHat, w, h, &pixelComparator);
	ComparatorImageResult result = comparatorCustom.run(epsilonCustom);

	TEST_ASSERT(result.isEgal);

	//cout << " #error 	= " << result.nbErreur << endl;
	//cout << " deltaMax	= " << result.deltaMax << endl;
	//cout << " deltaMin	= " << result.deltaMin << endl;
	}

    // Liberation memoires
	{
	HANDLE_ERROR(cudaFree(ptrDevDamierHat));
	delete[] ptrDamierSrc;
	delete[] ptrDamierHat;
	}
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

void TestDamier::fillImageCPU(cpu::uchar4* ptrTabPixel, int w, int h)
    {
    //TODO by user !
    }

void TestDamier::fillImageGPU(uchar4* ptrDevTabPixel, int w, int h)
    {
    //TODO by user!
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

