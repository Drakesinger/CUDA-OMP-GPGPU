#include <iostream>
#include <boost/program_options.hpp>

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

using std::cout;
using std::endl;

namespace po = boost::program_options;

using po::options_description;
using po::value;
using po::variables_map;
using po::store;
using po::parse_command_line;
using po::notify;

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

bool useOption(int argc, char** argv);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static bool use(double a, double b);
static bool help(const options_description& description);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * http://www.boost.org/doc/libs/1_55_0/doc/html/program_options/tutorial.html#idp163291912
 */
bool useOption(int argc, char** argv)
    {
    double a;
    double b;

    options_description description("Allowed options");
    description.add_options()
	    ("help", "produce help message")
	    ("a", value<double>(&a)->default_value(3.14), "explain here what is a ... Example: --a=2.22")
	    ("b", value<double>(&b)->default_value(1.11), "explain here what is b ... Example: --a=3.33");

    variables_map mapVariableValue;
    store(parse_command_line(argc, argv, description), mapVariableValue);
    notify(mapVariableValue);

    if (mapVariableValue.count("help"))
	{
	return help(description);
	}
    else
	{
	return use(a, b);
	}
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

bool use(double a, double b)
    {
    cout << "[Use Option] : " << endl << endl;

    cout << "a= " << a << endl;
    cout << "b= " << b << endl;
    cout << endl;

    return true;
    }

bool help(const options_description& description)
    {
    cout << "[Help] " << endl<<endl;

    cout << description << endl<<endl;

    cout<< "Write help here ..."<<endl<<endl;

    return true;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

