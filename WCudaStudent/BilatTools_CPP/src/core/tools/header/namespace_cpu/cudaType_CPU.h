#ifndef CUDA_TYPE_CPU_H_
#define CUDA_TYPE_CPU_H_

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

// Attention 	: code duplicated : aussi dans shared_lib api image
// Contrainte 	: Les deux versions doivent etre identique

namespace cpu
    {

    #define uchar unsigned char
    #define uint unsigned int
    #define ulong unsigned long

    struct float2
	{
	    float x;
	    float y;
	};

    struct float3
	{
	    float x;
	    float y;
	    float z;
	};

    struct uchar4
	{
	    uchar x;
	    uchar y;
	    uchar z;
	    uchar w;
	};
    }

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
