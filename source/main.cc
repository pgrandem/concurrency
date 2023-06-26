/// main.cc
/// ************************************************************************ ///
/// main.cc for "concurrency"
/// Pierre GRANDEMANGE
/// 27/06/2023
/// ************************************************************************ ///

/// includes and namespaces
/// ****************************************************************************
#include <algorithm>
#include <iostream>	
#include <thread>
using namespace std;



/// prototypes
/// ****************************************************************************
void fun();



/// main program
/// ****************************************************************************
int main()
{
	vector<thread> workers;
	for(size_t i=0; i<10; i++) {
		workers.push_back( thread( [i](){ 
			cout << "in thread " << i << endl; 
		}));
	} 
	
	cout << "hi rep" << endl;
	
	for_each( workers.begin(), workers.end(), [](std::thread & th) { 
		th.join(); 
	});

	return 0;
}





/// functions
/// ****************************************************************************

/// fun
/// ----------------------------------------------------------------------------
/// hello rep test function
void fun() { cout << endl << "hi rep, you are awesome!" << endl; }

