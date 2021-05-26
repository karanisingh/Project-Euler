//problem6.cpp: this file contains the function for the solution for problem 6

/*
* Problem 6: Sum Square Difference
* 
* The sum of the squares of the first ten natural numbers is 385
* 
* The square of the sum of the first ten natural numbers is 3025
* 
* Hence the difference between the sum of the quares of the first ten natural numbers and the square of the sum is 3025 - 385 = 2640
* 
* Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum
* 
* Solution: 25164150
* Time: 0 ms
*/

#include "kmath.h"

//no clever strategy needed, simple computation
int problem6()
{
	//use helper functions for readability
	return kmath::squareSums() - kmath::sumSquares();
}
