/// localFunctions.h
/// ************************************************************************ ///
/// local functions
/// Pierre GRANDEMANGE
/// 01/03/2022
/// ************************************************************************ ///

#ifndef DEF_LOCALFUNCTIONS
#define DEF_LOCALFUNCTIONS

/// includes
/// ****************************************************************************
/// standard library
#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <future>
#include <iostream>	
#include <list>
#include <string>
#include <thread>
/// root classes
/// rep classes
#include <RNNData.h>
#include <RNNFast.h>
#include <RNNTrainer.h>
/// rep namespaces







/// concu_part5
/// ----------------------------------------------------------------------------
void concu_part5_main();







/// concu_fnn_main
/// ----------------------------------------------------------------------------
void concu_rnn_main();

/// concu_fnn_ffwd
/// ----------------------------------------------------------------------------
template <class T>
void concu_rnn_ffwd(
	std::promise<T> 	&& 	prom_cost, 
	RNNFast<T>* 			& 	net,
	T* 					& 	inp,
	T* 					& 	tar
);

/// concu_fnn_test
/// ----------------------------------------------------------------------------
void concu_rnn_test(double* ptr);





/// concu_part4
/// ----------------------------------------------------------------------------
void concu_part4_main2();
std::string concu_part4_fun(); 
void concu_part4_main();
void concu_part4_thfun(std::promise<std::string> && prms); 

/// concu_part3
/// ----------------------------------------------------------------------------
void concu_part3_main();
void concu_part3_toSin(std::list<double> && list); 

/// concu_part2
/// ----------------------------------------------------------------------------
void concu_part2();
void concu_part2_thfun(int & i);
void concu_part2_test(std::vector<std::thread> & workers);

/// concu_part1
/// ----------------------------------------------------------------------------
void concu_part1();




#endif /// DEF_LOCALFUNCTIONS