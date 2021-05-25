//problem10.cpp: this file contains the function for the solution for problem 10

/*
* Problem 10: Summation of Primes
* 
* The sum of the primes below 10 is 17
* 
* Find the sum of all the primes below two million
* 
* Solution: 142913828922
* Time: 
*/

#include "kmath.h"

//This problem takes a long time if you choose to do brute force. 
//I have implemented the Sieve of Arastothenes
long problem10()
{
	int primes[2000000]{ 1 };

	primes[0] = 0;
	primes[1] = 1;

	kmath::sieve(primes);

	long sum{ 0 };
	for (int i = 1; i < 2000000; ++i)
	{
		if (primes[i] == 1) sum += i;
	}
	return sum;

}