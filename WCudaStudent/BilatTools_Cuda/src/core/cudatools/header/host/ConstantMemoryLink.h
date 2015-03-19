#ifndef CONSTANT_MEMORY_LINK_H_
#define CONSTANT_MEMORY_LINK_H_


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

struct ConstantMemoryLink
    {
	void** ptrDevTab;	 // void** pour la g�n�ricit�
	int n; 			// #octets de tout le tab
	size_t sizeAll; 	// nb case du tableau
    };


#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/