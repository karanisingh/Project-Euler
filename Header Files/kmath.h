//kmath.h: Header file for my custom math namespace's declarations
#pragma once

namespace kmath
{
	//Swaps two values by using a temporary variable and reassignment through pointers
	template <typename T>
	void swap(T* x, T* y)
	{
		int temp = *x;
		*x = *y;
		*y = temp;
	}

	//Determines if a value is prime by brute force with small optimizations
	template <typename T>
	bool isPrime(T n)
	{
		//OPTIMIZATION check even case once
		if (n % 2 == 0) return false;

		//OPTIMIZATION only need to check odds up until sqrt(n)
		for (T i = 3; i * i <= n; i += 2)
		{
			if (n % i == 0) return false;
			else continue;
		}
		return true;
	}

	bool isPalindrome(int num);      //helper function for problem 4
	bool isDivisible(int num);       //helper function for problem 5
	int sumSquares(void);            //helper function for problem 6
	int squareSums(void);            //helper function for problem 7
	void sieve(int  (&primes)[2000000]);         //helper function for problem 10
	int numDivisors(long num);       //helper function for problem 12
}
