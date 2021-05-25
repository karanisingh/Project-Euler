//problem5.cpp: this file holds the function for the solution for problem 5

/*
* Problem 5: Smallest Multiple
* 
* 2520 is the smallest number that can be divided by each of the numbers from 1 to 10
* without any remainder.
* 
* What is the smallest positive number that is evenly divisible by all of the numbers 
* from 1 to 20?
* 
* Solution: 232792560
* Time: 2.5 Seconds
*/


/*
* Using discrete math, this can be easily solved without the use of programming.
* 
* First find the prime factorization of each number:
* 20 = 2^2 * 5
* 19 = 19
* 18 = 2 * 3^2
* 17 = 17
* 16 = 2^4
* 15 = 3 * 5
* 14 = 2 * 7
* 13 = 13
* 11 = 11
* 
* This encompasses all of the numbers, so all you have to do is multiply the greatest
* power of each prime together
* 2^4 * 3^2 * 5 * 7 * 11 * 13 * 17 * 19 = 232792560
*/

#include "kmath.h"

int problem5()
{
	int answer{ 0 };

	//Check each even-number after 2500
	for (int i = 2522;; i += 2)
	{
		if (kmath::isDivisible(i)) return i;
		else continue;
	}
}