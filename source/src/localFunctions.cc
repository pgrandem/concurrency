/// localFunctions.cc
/// ************************************************************************ ///
/// local functions 
/// Pierre GRANDEMANGE
/// 01/03/2022
/// ************************************************************************ ///

#include "localFunctions.h"
using namespace std;

/// explicit instanciation
/// ****************************************************************************
/// see https://stackoverflow.com/questions/495021/
/// why-can-templates-only-be-implemented-in-the-header-file
template void concu_rnn_ffwd<double>(
	std::promise<double> 	&& 	prom_cost, 
	RNNFast<double>* 			& 	net,
	double* 							& 	inp,
	double* 							& 	tar
);





/// local functions
/// ****************************************************************************



/// concu_part5
/// ----------------------------------------------------------------------------
void concu_part5_main()
{
	cout << "main thread id: " << this_thread::get_id() << endl;
	
	vector<future<void>> futures;
	for(size_t i=0; i<1000; i++ ) {
		future fut = async([] {
			this_thread::sleep_for(chrono::seconds(1));
			cout << this_thread::get_id() << "  ";
		});
		futures.push_back(move(fut));
	}

	for_each(futures.begin(), futures.end(), [](future<void> & fut) {
		fut.wait();
	});
	cout << endl;
	this_thread::sleep_for(chrono::seconds(5));
}









/// concu_fnn_main
/// ----------------------------------------------------------------------------
void concu_rnn_main()
{
	/// hi dude
	cout << endl << "hi dude" << endl;
	
	/// parameters
	const size_t 					trsam = 13;
	const size_t 					batch = 4;
	const size_t 					tesam = 13;
	const string					pname = "concurrency";
	const vector<size_t> 	nnphl = {30};
	
	/// generate data
	RNNData<double>* dnn = RNNData<double>::mnist(23, 23);
	
	/// generate baby network
	const size_t 					sinpu = dnn->getinputsize();
	const size_t 					starg = dnn->gettargetsize();
	RNNFast<double>* rnn = new RNNFast<double>(pname, sinpu, starg, nnphl);


	/// format data
	vector<vector<double>>* ptri = dnn->ptrtrin();
	vector<vector<double>>* ptrt = dnn->ptrtrta();
	vector<vector<double*>> trin = RNNTrainer<double>::data_batch(ptri, batch);
	vector<vector<double*>> trta = RNNTrainer<double>::data_batch(ptrt, batch);
	
	/// multithreading format
	vector<promise<double>> cost_prom;
	vector<future<double>> 	cost_futu;
	vector<thread>					cost_thre;
	for(size_t b=0; b<batch; b++) { 
		promise<double> temp_prom;
		future<double> 	temp_futu = temp_prom.get_future();
		cost_prom.push_back(move(temp_prom));
		cost_futu.push_back(move(temp_futu)); 
	}
	
	/// training loop
	for(size_t t=0; t < trin.size(); t++) {
		cost_thre.clear();
		
		/// thread/batch loop
		for(size_t b=0; b < trin[t].size(); b++) {
			//thread tmp([]{
			//	cout << this_thread::get_id() << endl;
			//});
			//thread tmp(
			//	&concu_rnn_ffwd<double>, 
			//	move(cost_prom[b]), 
			//	ref(rnn), 
			//	ref(trin[t][b]),
			//	ref(trta[t][b])
			//);
			thread th( &concu_rnn_test, cref(trin[t][b]) );
			
			cost_thre.push_back(move(th));
			//cout << "debug b = " << b << endl;
			//cout << cost_futu[b].get() << endl;
		}
		
		/// join threads
		//for(size_t b=0; b < trin[t].size(); b++) { cost_thre[b].join(); }
		for_each(cost_thre.begin(), cost_thre.end(), [](thread & th){
				th.join();
		});

		/// dump message after join
		cout << "afterthread message"  << endl << endl;
	} 

	/// end dump message
	cout << endl << "the end" << endl;
}

/// concu_fnn_ffwd
/// ----------------------------------------------------------------------------
template <class T>
void concu_rnn_ffwd(
	std::promise<T> 	&& 	prom_cost, 
	RNNFast<T>* 			& 	net,
	T* 								& 	inp,
	T* 								& 	tar
)
{
	/// dump
	cout << this_thread::get_id() << endl;

}

/// concu_fnn_test
/// ----------------------------------------------------------------------------
void concu_rnn_test(double* ptr)
{
	cout << ptr << endl;
}












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

	/// plot list
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








