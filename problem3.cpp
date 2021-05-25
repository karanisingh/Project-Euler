//problem3.cpp: this file holds the function for the solution for problem 3

/*
* Problem 3: Largest Prime Factor
* 
* The prime factors of 13195 are 5, 7, 13, and 29.
* 
* What is the largest prime factor of the number 600851475143 ?
* 
* Solution: 6857
* Time: 292 ms
*/

#include "kmath.h"


//This one still relies mostly on bruteforce, but includes 2 key optimizations
int problem3()
{
	long long g = 600851475143;

	for (long long i = 3; i <= g; i+=2) {
		if (g % i == 0) 
		{
			if (kmath::isPrime(g / i)) return int(g / i);
		}
	}
}