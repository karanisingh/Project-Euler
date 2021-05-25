//problem7.cpp: this file contains the function for the solution for problem 7

/*
* Problem 7: 10001st Prime
* 
* By listing the first six prime numbers: 2, 3, 5, 7, 11, adn 13, we can see that the
* 6th prime is 13.
* 
* What is the 10001st prime numer?
* 
* Solution: 104743
* Time: 9 ms
*/

#include "kmath.h"

//brute force with kmath function
int problem7()
{
	//int target{ 0 };
	int counter{ 0 };
	for (int i = 1; counter <= 10001; ++i)
	{
		if (kmath::isPrime(i)) 
		{
			++counter;
			if (counter == 10001) return i;
		}
	}
}