#ifndef CHRONOS_H
#define CHRONOS_H

#include <string>

using std::string;
using std::ostream;

class Chronos
    {
    public:

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

	Chronos();
	virtual ~Chronos();

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

	void start();
	double stop();
	double timeFlight() const;
	double getDeltaTime() const;
	void print(const string& titre = "") const;
	void print(ostream& stream, const string& titre = "") const;

	/*--------------------------------------*\
	 |*		Friend			*|
	 \*-------------------------------------*/

	friend ostream& operator <<(ostream& stream, const Chronos& chrono);

    private:

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

	static double time();

	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/

	double timeStart;
	double timeStop;
	double deltaTime;
	bool isRunning;
    };

#endif
