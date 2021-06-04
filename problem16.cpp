//problem16.cpp: this file contains the function for the solution for problem 16

/*
* Problem 16: Power Digit Sum
* 
* 2^15 = 32768 and the sum of its digits is 26
* 
* What is the sum of the digits of the number 2^1000?
* 
* Solution: 1366
* Time: 14 ms
*/
#include "BigInteger.h"

/*
* The strategy is to use a BigInteger class to calculate the number.
* 
* Could have written less code by creating a function for the bigint, but
* decided that it would be beneficial to learn how to implement bigint, as
* it could be useful later on!
*/
 int problem16()
{
	//initialize the BigInteger with 1
	std::string s = "1";
	BigInteger myInt(s);

	//calculate 2^1000
	for (int i = 1; i <= 1000; ++i)
	{
		myInt = myInt * 2;
	}

	//add up the digits of 2^1000
	s = myInt.getValue();
	int sum{ 0 };
	for (auto x : s)
	{
		sum += (x - '0');
	}

	//return the sum
	return sum;
}