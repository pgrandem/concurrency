/// main.cc
/// ************************************************************************ ///
/// main.cc for "concurrency"
/// Pierre GRANDEMANGE
/// 27/06/2023
/// ************************************************************************ ///

/// includes and namespaces
/// ****************************************************************************
/// standard library
/// my headers
#include <localFunctions.h>
using namespace std;



/// prototypes
/// ****************************************************************************
void fun();



/// main program
/// ****************************************************************************
int main()
{
	/// main function
	//concu_part5_main();
	concu_rnn_main();



	/// the end
	cout << endl;
	return 0;
}





/// functions
/// ****************************************************************************

/// fun
/// ----------------------------------------------------------------------------
/// hello rep test function
void fun() { cout << endl << "hi rep, you are awesome!" << endl; }

