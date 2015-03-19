#ifndef CU_CPP_H_
#define CU_CPP_H_


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*---------------*\
 |* HostDevice Side  *|
 \*---------------*/

#include "DomaineMath.h"
#include "DomaineEcran.h"

#include "CalibreurF.h"
#include "IntervalF.h"

#include "ColorTools.h"
#include "IndiceTools.h"

/*---------------*\
 |*  Host Side  *|
 \*---------------*/

#include "ImageFonctionel_A.h"
#include "Image_A.h"
//#include "CanvasImageViewers.h"// pas utilisable dans cu car utilise boost
//#include "GLUTImageViewers.h" // pas utilisable dans cu car utilise boost

#include "cudaType.h"

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
