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


/*
* Strategy: brute force, has some optimization though
*/

int problem3()
{
	//the value to test
	long long g = 600851475143;

	//start at 3 and check the odd numbers since we know it cant be even
	for (long long i = 3; i <= g; i+=2) {

		//check if factor
		if (g % i == 0) 
		{
			//check if prime, if it is, return the complement of that, which would be the largest since we are starting from the smallest factors
			if (kmath::isPrime(g / i)) return int(g / i);
		}
	}
	return 0;
}
