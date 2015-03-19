#ifndef MATH_TOOLS_
#define MATH_TOOLS_

#define PI_FLOAT 3.141592653589793f

#ifndef PI
#define PI 3.1415926535897932384626433832795028841971693993751
#endif

#ifndef MIN
#define MIN(X,Y) ((X)<(Y)?(X):(Y))
#endif

#ifndef MAX
#define MAX(X,Y) ((X)>(Y)?(X):(Y))
#endif

class MathTools
    {
    public:

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

	MathTools();

	/*--------------------------------------*\
	 |*		Destructor		*|
	 \*-------------------------------------*/

	virtual ~MathTools();

	/*--------------------------------------*\
	 |*		Methodes Static		*|
	 \*-------------------------------------*/

	/*---------------*\
	|*	Float  	*|
	 \*---------------*/

	/**
	 * Relatif au max(x1,x2)
	 */
	static bool isEquals(float x1, float x2, float epsilon = 0);

	/**
	 * Relatif a reference
	 * epsilon pas de valeur par default, sinon meme signature que autre methode (overload)
	 */
	static bool isEquals(float a, float b, float reference, float epsilon); //

	/**
	 * Relatif, un a un (au max des 2)
	 * Hyp: tab de meme size n
	 */
	static bool isEquals(float* tabA, float* tabB, int n, float epsilon = 0);

	/**
	 * Relatif par rapport au max de la série
	 * Hyp: tab de meme size n
	 */
	static bool isEqualsRelatifMax(float* tabA, float* tabB, int n, float epsilon = 0);

	/*---------------*\
	|*	Double  *|
	 \*---------------*/

	/**
	 * Relatif au max(x1,x2)
	 */
	static bool isEquals(double x1, double x2, double epsilon = 0);


	/*---------------*\
	|*	Long  	*|
	 \*---------------*/

	/**
	 * Absolu
	 */
	static bool isEquals(long x1, long x2);

	/*---------------*\
	|*	isPower2  *|
	\*---------------*/

	static bool isPower2(long i);
	static bool isPower2(int i);
	static bool isPower2(unsigned int i);

    private:

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

	static float maxAbs(float a, float b);

	/**
	 * Hyp: tab de meme size n
	 */
	static float maxAbs(float* tabA, float* tabB, int n);

	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/

    };

#endif
