#ifndef COLOR_TOOL_GPU_H
#define COLOR_TOOL_GPU_H

#include "both_define.h"
#include "builtin_types.h" // pour float3


// TODO cuda ameliorer

namespace gpu
    {

    class ColorTools
	{
	    /*--------------------------------------*\
	   |*		  HSB_TO_RVB     	*|
	     \*-------------------------------------*/

	    /*--------------------------------------*\
	   |*		public			    *|
	     \*-------------------------------------*/

	public:

	    /**
	     * Convertir une couleur HSB en RGB !
	     * H,S,B in [0,1]
	     * R,G,B in [0,255]
	     */
	    __BOTH__
	    static void HSB_TO_RVB(const float3& hsb01, uchar4* ptrRVBA)
		{
		ColorTools::HSB_TO_RVB(hsb01.x, hsb01.y, hsb01.z, &ptrRVBA->x, &ptrRVBA->y, &ptrRVBA->z);
		}

	    /**
	     * Convertir une couleur HSB en RGB !
	     * H,S,B in [0,1]
	     * R,G,B in [0,255]
	     */
	    __BOTH__
	    static void HSB_TO_RVB(float h01, uchar4* ptrRVBA)
		{
		ColorTools::HSB_TO_RVB(h01, 1.0f, 1.0f, &ptrRVBA->x, &ptrRVBA->y, &ptrRVBA->z);
		}

	    /**
	     * Convertir une couleur HSB en RGB !
	     * H,S,B in [0,1]
	     * R,G,B in [0,255]
	     */
	    __BOTH__
	    static void HSB_TO_RVB(float h01, float s01, float b01, uchar4* ptrRVBA)
		{
		ColorTools::HSB_TO_RVB(h01, s01, b01, &ptrRVBA->x, &ptrRVBA->y, &ptrRVBA->z);
		}

	    /**
	     * Convertir une couleur HSB en RGB !
	     * H,S,B in [0,1]
	     * R,G,B in [0,255]
	     */
	    __BOTH__
	    static void HSB_TO_RVB(float H, float S, float V, unsigned char *ptrR, unsigned char *ptrG, unsigned char *ptrB)
		{
		//float H = profondeur / 255.0;
		//float S = 1;
		//float V = 1;
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
	    |*		private			    *|
	     \*-------------------------------------*/

	};
    }
#endif

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
