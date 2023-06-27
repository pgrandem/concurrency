/// localFunctions.h
/// ************************************************************************ ///
/// local functions
/// Pierre GRANDEMANGE
/// 01/03/2022
/// ************************************************************************ ///



/// includes
/// ****************************************************************************
/// standard library
#include <string>
/// root classes
/// rep classes
/// rep namespaces

/// const global variable (external linkage) defined in main
/// ****************************************************************************
extern const clock_t			gtimerstart;			
extern const std::string 	rep;
extern const std::string	projectFolder;
extern const std::string	dataFolder;
extern const std::string 	repNamespaces;
extern const std::string 	repObjects;

/// manual for this code
/// ****************************************************************************
/// - functions should be written in alphabetical order

/// debug functions
/// ****************************************************************************

/// dumpCheck
/// ----------------------------------------------------------------------------
void dumpCheck();

/// dumpGlobals 
/// ----------------------------------------------------------------------------
/// dump the list of global variables
void dumpGlobals();



