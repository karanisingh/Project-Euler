//problem20.cpp: this file contains the function for the solution for problem 20

/*
* Problem 20: Factorial Digit Sum
* 
* Find the sum of the digits in the number 100!
* 
* Solution: 648
* Time: 3 ms
*/

/*
* Strategy: will use my big int class
*/

#include "BigInteger.h"

int problem20()
{
	// initialilze the big integer with 1
	int sum{ 0 };
	std::string init = "1";
	BigInteger theInt(init);

	//calculate 100!
	for (int i = 2; i <= 100; ++i)	theInt = theInt * i;

	// calculate the sume of the digits of 100!
	for (auto x : theInt.getContainer()) sum += x;

	return sum;
}