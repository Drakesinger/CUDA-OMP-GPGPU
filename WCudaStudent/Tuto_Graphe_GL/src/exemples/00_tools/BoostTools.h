#ifndef BOOST_TOOLS_H_
#define BOOST_TOOLS_H_

#include <boost/thread.hpp>
#include <boost/date_time.hpp>
#include <boost/pointer_cast.hpp>

using boost::static_pointer_cast;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class BoostTools
    {

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	BoostTools()
	    {
	    //Nothing
	    }

	virtual ~BoostTools()
	    {
	    //Nothing
	    }

	/*--------------------------------------*\
	|*		Methode			*|
	 \*-------------------------------------*/

    public:

	static void sleep(long delayMS)
	    {
	    boost::this_thread::sleep_for(boost::chrono::milliseconds(delayMS));
	    }

	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
