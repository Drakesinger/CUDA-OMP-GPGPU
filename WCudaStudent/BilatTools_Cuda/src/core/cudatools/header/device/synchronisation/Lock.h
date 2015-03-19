#ifndef LOCK_CUDA_H_
#define LOCK_CUDA_H_

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * General :
 *
 * 	A Mutex will act like something of a traffic signal that governs access to some resources.
 * 	When a thread reads a 0 from the mutex,it interprets this valu as a "green lignt" indicating that no other thread is using the memory.
 * 	Therefore, the thread is free to lock the memory and make whatever changes it desires,free of interference from other threads.
 * 	To lock the memory location in nquestion, the thread writes a 1 to the mutex.
 * 	This will act as a "red light" for potentially competing threads.
 * 	The competing threads must then wait until the owner has written a 0 to the mutex beforfe they can attempt to modify the locked memory.
 *
 * Interet
 * 	On utilise un lock lorsque l'opération qui doit être synchroniser ne possède pas d'opérateur atomic (comme atomicADD, ...),
 * 	ou lorsqui'il s'agit de plusieurs opérations à synchroniser (joue alors le role de section critique)
 *
 * Note :
 *
 * 	Lock ne laisse aucune trace coté host, il s'instancie only coté device: Code moins invasif
 * 	LockMixte laisse une trace coté host. Code plus invasif
 *
 * Use (Device side only)
 *
 *
 *	// Global variable of .cu
 * 	__device__ int mutex=0;	// Attention à l'initialisation
 *
 *	// variable local inside a kernel (same .cu as variable mutex)
 * 	Lock lock=Lock(&mutex);
 *
 * 	lock.lock();
 * 	doSomething();
 * 	lock.unlock();
 *
 */
class Lock
    {

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	/**
	 * Toutes les instance se partagent la meme adresse du mutex ptrDevMutexGM
	 */
	__device__
	Lock(int* ptrDevMutexGM)
	    {
	    this->ptrDevMutexGM = ptrDevMutexGM;
	    }

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	__device__
	void lock(void)
	    {
	    // Goal :
	    // 		if (*ptrDev_mutex==0) {*ptrDev_mutex==1}
	    // 		But must be thread safe!
	    //
	    // Solution:
	    // 		atomicCAS  = atomic Compare And Swap
	    // 		Prototype : 	c atomicCAS(ptr,a,b)
	    // 		Action :	compare ptr avec a, si egale affecte b à ptr, renvoie ptr

	    // Tant que ptrDev_mutex!=0 le thread cuda boucle sur while
	    // Des qu'il vaut 0, il met le mutex à 1 et lock se termine
	    while (atomicCAS(ptrDevMutexGM, 0, 1) != 0);
	    }

	__device__
	void unlock(void)
	    {
	    // Goal :
	    //		Put 1 in the mutex
	    //
	    // Solution 1:
	    //
	    //		*ptrDev_mutex=0;
	    //		Aucun thread en competition ici. L'affectation n'a pas besoin d'être atomique.
	    //		Solution satisfaisante.
	    //
	    // Solution 2 (prefered for symetric approach)
	    //
	    //		Une solution atomique

	    // Echange et renvoie la valeur originale
	    atomicExch(ptrDevMutexGM, 0);
	    }

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:

	int* ptrDevMutexGM;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
