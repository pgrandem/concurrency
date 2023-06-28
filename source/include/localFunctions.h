/// localFunctions.h
/// ************************************************************************ ///
/// local functions
/// Pierre GRANDEMANGE
/// 01/03/2022
/// ************************************************************************ ///

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
/// rep namespaces


/// concu_fnn_main
/// ----------------------------------------------------------------------------
void concu_rnn_main();


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




