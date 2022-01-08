//problem21.cpp: this file contains the function for the solution for problem 21

/*
* Problem 21: Amicable numbers
* 
* Let d(n) be defined as the sum of proper divisors of n
* If d(a) = b and d(b) = a, where a != b, then a and b are an amicable pair and each of a and b are called amicable numbers
* 
* Evaluate the sum of all the amicable numbers under 10000
* 
* Solution: 31626
* Time: 3 ms
*/

/*
* Strategy: Brute force, no need to really optimize. Run through every number and record if it is an amicable number
* Could optimize by having a hash table that puts in amicable pairs together, and can later check if an amicable number has already been added to the sum
*/

int sumOfDivisors(int n)
{
	// 1 has no divisors and is no an amicable number
	// 2 has 1 divisor and is not an amicable number
	if (n == 1) return 0;
	if (n == 2) return 1;
	
	if (n & 1)		// if odd, only have to check odd divisors
	{
		int sum{ 1 };
		for (int i = 3; i * i <= n; i+=2)
		{
			if (n % i == 0) sum += (i + (n / i));
			if (i * i == n) sum -= i;
		}
		return sum;
	}
	else            // if even, have to check all divisors
	{
		int sum{ 1 + 2 + (n / 2) };
		for (int i = 3; i * i <= n; ++i)
		{
			if (n % i == 0) sum += (i + (n / i));
			if (i * i == n) sum -= i;
		}
		return sum;
	}
	
}

int problem21()
{
	int sum{ 0 };

	for (int i = 3; i < 10000; ++i)
	{
		int amicable_1{ sumOfDivisors(i) };
		if (i == sumOfDivisors(amicable_1) && i != amicable_1) sum += i;
	}

	return sum;
}

