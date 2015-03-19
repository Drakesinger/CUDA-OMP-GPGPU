#ifndef LOCK_MIXTE_H_
#define LOCK_MIXTE_H_

#include "cudaTools.h"

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
 * Use (host) :
 *
 *	LockMixte lock();
 *	kernel<<<dg,db>>>(...,lock,...); // pas besoin de memory managment MM
 *
 * Use (device):
 *
 * 	lock.lock();
 * 	doSomething();
 * 	lock.unlock();
 *
 */
class LockMixte
    {

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public :

	LockMixte(void)
	    {
	    int state = 0;
	    HANDLE_ERROR(cudaMalloc((void**) &ptrDev_mutex, sizeof(int)));
	    HANDLE_ERROR(cudaMemcpy(ptrDev_mutex, &state, sizeof(int), cudaMemcpyHostToDevice));
	    }

	/**
	 * Observation:
	 *
	 * 	Comme Lock est passer par valeur au kernel,ie par copie,deux objets au total sont vivants, un sur le cpu et sun sur le gpu.
	 * 	Le destructeur sera donc appeler 2x,la premiere fois, lors de la fin du kernel sur le gpu, la seconde fois sur le cpu.
	 * 	Comme cudaFree peut etre appeler sur le cpu ou gpu, le code ci-dessous est valide, mais sans le HANDLE_ERROR qui n'a aucun sens
	 * 	(affichage d'un message d'error) sur le GPU et qui est donc enlever ici.
	 * 	Heureusement cudaFree peut être appeler plusieurs fois de suite sans probleme,mais un seul appel suffirait!
	 *
	 * Attention:
	 *
	 * 	Sur le GPU, il ne faut jamais passer Lock par valeur, car sinon, la premiere instance detruite, detruit ptrDev_mutex !!
	 * 	et le mutex devient alors inutilisable!
	 */
	~LockMixte(void)
	    {
	   // HANDLE_ERROR(cudaFree(ptrDev_mutex)); // HANDLE_ERROR : pas possible car executer aussi sur le GPU
	    cudaFree(ptrDev_mutex);
	    }

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public :

	__device__ void lock(void)
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
	    while (atomicCAS(ptrDev_mutex, 0, 1) != 0);
	    }

	__device__ void unlock(void)
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
	    atomicExch(ptrDev_mutex, 0);
	    }

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private :

	int* ptrDev_mutex; // Espace adressage GPU, en global memory GM
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
