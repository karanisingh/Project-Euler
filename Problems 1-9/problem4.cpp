//problem4.cpp: this file holds the function for the solution for problem 4

/*
* Problem 4: Largest Palindrome Product
* 
* A palindromic number reads the same both ways. The largest palindrome made from
* the product of two 2-digit numbers is 9009 = 91 x 99.
* 
* Find the largest palindrome made from the product of two 3-digit numbers
* 
* Solution: 906609
* Time: 22 ms
*/

#include "kmath.h"

/*
* Strategy: brute force, no way to optimize it more than it currently is
*/

int problem4()
{
	int answer{ 0 };
	//iterate through every number from 1
	for (int i = 999; i >= 100; --i)
	{
		for (int j = 999; j >= 100; --j)
		{
			//check if it is a palindrome and if it is larger than current answer
			if (kmath::isPalindrome(i * j) && i * j > answer) answer = i * j;
		}
	}

	return answer;
}
