// Objectif:
//
//		Faciliter la vie de l'utilisateur!
//
// Probleme:
//
//	Exemple (api image)
//
//		Methodologie 1 (utilisation namespace explicite)
//
//			Compilation gcc = > cpu::Image	#include "Image_CPU.h"
//			Compilation nvcc => gpu::Image	#include "Image_GPU.h"
//
//			Avantage	: On peut utiliser en meme temps (meme exe) la vesrion cuda(namespace gpu) et non cuda (namespace cpu) de l'api-image
//			Inconvenient	: syntaxe lourde
//
//		Methodologie 2 (utilisation de smart switch a priorite cuda)
//
//			Code (sans namespace)
//
//				Image	#include "Image.h"
//
//			Compilation gcc  = > utilise automatiquemnt namespace cpu
//						=> et donc indirectememt 	cpu::Image	#include "Image_CPU.h"
//
//			Compilation nvcc = > utilise automatiquemnt namespace gpu
//						=> et donc indirectememt 	gpu::Image	#include "Image_GPU.h"
//
//
//			Avantage	: syntaxe ligth,portage de code facile entre version cpu et gpu, c'est le compilateur qui oriente
//			Inconvenient	: On peut pas utiliser en meme temps (meme exe) la vesrion cuda(namespace gpu) et non cuda (namespace cpu) de l'api-image
//
//			Contrainte :
//						Injecter la variable 
//
//								-D__CBI_CUDA__	
//	
//						ou mieux injecter la variable pour les projets non cuda
//
//								-DCBI_NO_CUDA
//			Note
//					L'utilisation de la variable 
//				
//								__CUDACC__
//		
//					ne marche pas, elle est vrai que pour les portions de codes compiliés par nvcc, et false lorsque nvcc demande à gcc de compiler
		
/*----------------------------------------------------------------------*\
 |*				Pre-defined Compiler Macros								*|
 \*---------------------------------------------------------------------*/

// http://sourceforge.net/p/predef/wiki/Compilers/

// http://msdn.microsoft.com/en-us/library/b0084kay.aspx
// https://gcc.gnu.org/onlinedocs/cpp/Common-Predefined-Macros.html
// http://sourceforge.net/p/predef/wiki/Home/

// #ifdef __GNUC__
// #if defined(_MSC_VER)
// #ifdef __CBI_CUDA__
