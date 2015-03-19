/*
 * The two methode HSB_TO_RGB and RGB_TO_HSB are from http://www.easyrgb.com/index.php?X=MATH&H=21#text21
 */
#include "ColorTools_CPU.h"

#define max(a,b) (a>=b?a:b)
#define min(a,b) (a<=b?a:b)

namespace cpu
    {

//#define RED_MASK 	0x000000FF
//#define GREEN_MASK 	0x0000FF00
//#define BLUE_MASK	0x00FF0000
//#define ALPHA_MASK 	0xFF000000;

    /*--------------------------------------*\
|*		 HSB_TO_RVB    		*|
     \*-------------------------------------*/

    void ColorTools::HSB_TO_RVB(const float3& hsb, uchar4* ptrRVBA)
	{
	ColorTools::HSB_TO_RVB(hsb.x, hsb.y, hsb.z, &ptrRVBA->x, &ptrRVBA->y, &ptrRVBA->z);
	}

    void ColorTools::HSB_TO_RVB(float h01, uchar4* ptrRVBA)
	{
	ColorTools::HSB_TO_RVB(h01, 1.0f, 1.0f, &ptrRVBA->x, &ptrRVBA->y, &ptrRVBA->z);
	}

    void ColorTools::HSB_TO_RVB(float h01, float s01, float b01, uchar4* ptrRVBA)
	{
	ColorTools::HSB_TO_RVB(h01, s01, b01, &ptrRVBA->x, &ptrRVBA->y, &ptrRVBA->z);
	}

    /**
     * Inputs :
     * 	H,S,B valeur comprise entre [0,1]
     *
     * Outpus :
     *	R,G,B le resultat compris dans les valeurs [0-255]
     */
    void ColorTools::HSB_TO_RVB(const float H, const float S, const float V, unsigned char *ptrR, unsigned char *ptrG, unsigned char *ptrB)
	{
	if (S == 0) //HSV from 0 to 1
	    {
	    *ptrR = V * 255;
	    *ptrG = V * 255;
	    *ptrB = V * 255;
	    }
	else
	    {
	    float var_h = H * 6;
	    if (var_h == 6)
		{
		var_h = 0;
		} //H must be < 1

	    unsigned char var_i = (unsigned char) var_h; //Or ... var_i = floor( var_h )
	    float var_1 = V * (1 - S);
	    float var_2 = V * (1 - S * (var_h - var_i));
	    float var_3 = V * (1 - S * (1 - (var_h - var_i)));

	    float var_r, var_g, var_b;
	    if (var_i == 0)
		{
		var_r = V;
		var_g = var_3;
		var_b = var_1;
		}
	    else if (var_i == 1)
		{
		var_r = var_2;
		var_g = V;
		var_b = var_1;
		}
	    else if (var_i == 2)
		{
		var_r = var_1;
		var_g = V;
		var_b = var_3;
		}
	    else if (var_i == 3)
		{
		var_r = var_1;
		var_g = var_2;
		var_b = V;
		}
	    else if (var_i == 4)
		{
		var_r = var_3;
		var_g = var_1;
		var_b = V;
		}
	    else
		{
		var_r = V;
		var_g = var_1;
		var_b = var_2;
		}

	    //RGB results from 0 to 255
	    *ptrR = (unsigned char) (var_r * 255);
	    *ptrG = (unsigned char) (var_g * 255);
	    *ptrB = (unsigned char) (var_b * 255);
	    }
	}

    /*--------------------------------------*\
    |*		 RGB_TO_HSV  		*|
     \*-------------------------------------*/

    void ColorTools::RGB_TO_HSB(const unsigned char R, const unsigned char G, const unsigned char B, float &H, float &S, float &V)
	{
	//RGB from 0 to 255
	float var_R = (R / (float) 255);
	float var_G = (G / (float) 255);
	float var_B = (B / (float) 255);

	float var_Min = min(var_R, min(var_G, var_B)); //Min. value of RGB
	float var_Max = max(var_R, max(var_G, var_B)); //Max. value of RGB
	float del_Max = var_Max - var_Min; //Delta RGB value

	V = var_Max;

	if (del_Max == 0) //This is a gray, no chroma...
	    {
	    H = 0; //HSV results from 0 to 1
	    S = 0;
	    }
	else //Chromatic data...
	    {
	    S = del_Max / var_Max;

	    float del_R, del_G, del_B;
	    del_R = (((var_Max - var_R) / 6) + (del_Max / 2)) / del_Max;
	    del_G = (((var_Max - var_G) / 6) + (del_Max / 2)) / del_Max;
	    del_B = (((var_Max - var_B) / 6) + (del_Max / 2)) / del_Max;

	    if (var_R == var_Max)
		H = del_B - del_G;
	    else if (var_G == var_Max)
		H = (1 / 3) + del_R - del_B;
	    else if (var_B == var_Max)
		H = (2 / 3) + del_G - del_R;

	    if (H < 0)
		H += 1;
	    if (H > 1)
		H -= 1;
	    }
	}

    /*--------------------------------------*\
    |*		 int 			   *|
     \*-------------------------------------*/

    int ColorTools::toIntRGBA(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
	{
	int var_a = a << 24;
	int var_b = b << 16;
	int var_g = g << 8;
	int rgb = var_b ^ var_g ^ ((int) r) ^ var_a;

	return rgb;
	}

    int ColorTools::toIntRGBA(float r, float g, float b, float a)
	{
	return toIntRGBA((unsigned char) (r * 255.0), (unsigned char) (g * 255.0), (unsigned char) (b * 255.0), (unsigned char) (a * 255.0));
	}

    int ColorTools::HSB_TO_IntRGBA(float h01, float s01, float b01, float a01)
	{
	unsigned char result_r, result_v, result_b;
	ColorTools::HSB_TO_RVB(h01, s01, b01, &result_r, &result_v, &result_b);

	return toIntRGBA(result_r, result_v, result_b, (int) (a01 * 255.0));
	}

    void ColorTools::fromIntRGBA(const int rgba, unsigned char &r, unsigned char &g, unsigned char &b, unsigned char &a)
	{
	r = (unsigned char) rgba;
	g = (unsigned char) (rgba >> 8);
	b = (unsigned char) (rgba >> 16);
	a = (unsigned char) (rgba >> 24);
	}

    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

