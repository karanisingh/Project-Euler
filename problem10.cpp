//problem10.cpp: this file contains the function for the solution for problem 10

/*
* Problem 10: Summation of Primes
* 
* The sum of the primes below 10 is 17
* 
* Find the sum of all the primes below two million
* 
* Solution: 142 913 828 922
* Time: 22 ms
*/


/*
* Strategy: can't use brute force, too many loops, so used the Sieve of Eratosthenes
* 
* The strategy is to populate a list of integers up to a number, 
* Start at a number, and then remove all multiples of that number for the list
* Keep going, then all the remining numbers in the list are prime
*/

int list[2000000] = { 0 };

long long problem10()
{
	long long sum{ 0 };

	//initialize the list with the correct numbers, not even since they arent primes
	for (int i = 3; i < 2000000; i += 2) list[i] = i;

	//iterate through each number in the list
	for (int i = 3; i < 2000000; ++i)
	{
		//if the number has not already been eliminated, eliminate all of its multiples from the list
		if (list[i] != 0)
		{
			//eliminate all of the multiples
			for (int j = 3; j * i < 2000000; j+=2)	list[i * j] = 0;
		}
	}

	//sum up the elements in the list
	for (auto x : list)
	{
		sum += x;
	}

	//don't forget that 2 is prime!
	return sum + 2;
}
