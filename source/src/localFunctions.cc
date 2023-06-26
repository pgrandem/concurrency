/// localFunctions.cc
/// ************************************************************************ ///
/// local functions 
/// Pierre GRANDEMANGE
/// 01/03/2022
/// ************************************************************************ ///

#include "localFunctions.h"
using namespace std;




/// concu_part4
/// ----------------------------------------------------------------------------
void concu_part4_main2()
{
	future ftr = async(&concu_part4_fun);
	cout << "hello from main" << endl;
	string str = ftr.get(); 
	cout << str << endl;
}

string concu_part4_fun()
{
	string str = "hello from the future";
	return str;
}


void concu_part4_main()
{
	promise<string> prms ;
	future<string> 	ftr = prms.get_future();
	thread th(&concu_part4_thfun, move(prms));
	cout << "hello from main" << endl;
	try {
		string str = ftr.get();
		cout << str << endl;
	}
	catch(exception & e) {
		cout << e.what() << endl;
	}
	th.join();
}

void concu_part4_thfun(promise<string> && prms)
{
	try {
		string str = "hello from the future";
		//throw(std::exception("exception from the future!"));
		throw(std::exception());
		prms.set_value(str);
	}
	catch(...) {
		prms.set_exception(std::current_exception());
	}
	
}






/// concu_part3
/// ----------------------------------------------------------------------------
void concu_part3_main()
{
	list<double> list;
	/// acces list from main thread
	const double pi = 3.141592;
	const double epsilon = 0.0000001;
	for(double x=0.0; x < 2.*pi + epsilon; x += pi/16) {
		list.push_back(x);
	}
	/// start thread
	std::thread th(&concu_part3_toSin, move(list));
	/// join thread
	th.join();


}

void concu_part3_toSin(list<double> && list)
{
	this_thread::sleep_for(chrono::seconds(1));
	for_each(list.begin(), list.end(), [](double & x) { x = sin(x); } );

	/// plot lisr
	for_each(list.begin(), list.end(), [](double & x) {
		int count = static_cast<int>(10*x + 10.5);
		for( int i=0; i<count; i++ ) { cout << "*"; }
		cout << endl;
	});
}





/// concu_part2
/// ----------------------------------------------------------------------------
void concu_part2()
{
	vector<thread> workers;
	concu_part2_test(workers);
	
	cout << "hi rep" << endl;
	
	for_each( workers.begin(), workers.end(), [](std::thread & th) { 
		assert(th.joinable());
		th.join(); 
	});
}

void concu_part2_test(vector<thread> & workers)
{
	for(int i=0; i<8; i++) { 
		auto th = thread(&concu_part2_thfun, ref(i));
		workers.push_back(move(th));
		assert(!th.joinable());
	}; 
}

void concu_part2_thfun(int & i)
{
	cout << "in thread " << i << endl; 
}







/// concu_part1
/// ----------------------------------------------------------------------------
void concu_part1()
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
}








