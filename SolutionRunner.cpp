// Solution.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>                  // Will use high_resolution_timer to get duration of algorithm
#include "Solutions.h"             // The solutions

int main()
{
	auto start = std::chrono::high_resolution_clock::now();
	auto returnValue = problem4();          //this line is used to test specific solutions' functions
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << returnValue << "\n" << duration.count() << " milliseconds." << std::endl;
	
	return 0;
}
