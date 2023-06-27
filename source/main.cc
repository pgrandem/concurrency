/// main.cc
/// ************************************************************************ ///
/// main.cc for "nptf: Null Project To Fork"
/// Pierre GRANDEMANGE
/// 01/03/2022
/// ************************************************************************ ///

/// includes and namespaces
/// ****************************************************************************
/// standard library
#include <ctime>		/// clock_t, clock(), CLOCKS_PER_SEC
#include <iostream>		/// input output streams
#include <stdlib.h>		/// getenv, system
#include <string> 		/// c++ string types
/// root classes
/// rep classes
#include "RDump.h"
/// rep namespaces
/// local functions
#include "localFunctions.h"
/// namespace
using namespace std;

/// define initialized const global variable (external linkage)
/// ****************************************************************************
extern const clock_t 		gtimerstart(clock()); 			/// main timer
extern const std::string	projectFolder(getenv("mainFolder"));
extern const std::string	dataFolder(getenv("data"));
extern const std::string 	repNamespaces(getenv("repNamespaces"));
extern const std::string 	repObjects(getenv("repObjects"));

/// prototypes
/// ****************************************************************************
void hiRep();  							/// hello world test function

/// main program
/// ****************************************************************************
int main(int argc, char* argv[])
{
	/// main intro
	RDump::title("main.cc start");
			
	/// main : here it goes!
	hiRep();
	dumpGlobals();
	for( int i=1; i<argc; ++i  ) { cout << argv[i] << endl; }

	/// main outro
	RDump::title("main.cc end");
	RDump::timer(gtimerstart); cout << endl;
	return 0;
}





/// functions
/// ****************************************************************************

/// hiRep()
/// ----------------------------------------------------------------------------
/// hello rep test function
void hiRep() { cout << endl << "hi rep, you are awesome!" << endl; }

