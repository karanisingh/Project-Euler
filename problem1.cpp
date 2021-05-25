//problem1.cpp: This file holds the function for the solution for problem 1

/*
* Problem 1
* 
* If we list all the natural numbers below 10 that are multiples of 3 or 5, we get
* 3, 4, 6, and 9. The sum of these multiples is 23.
* 
* Find the sum of all the multiples of 3 or 5 below 1000.
* 
* Solution: 233168
* Time: 0 ms
*/

//No strategy, just brute force as this is a simple computational problem
int problem1()
{
	int sum{ 0 };

	for (int i = 3; i < 1000; ++i)
	{
		if (i % 3 == 0 || i % 5 == 0) {
			sum += i;
		}
	}
	
	return sum;
}