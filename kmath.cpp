//kmath.cpp: holds the definitions for my personal math namespace

namespace kmath
{
	void swap(int* x, int* y)
	{
		int temp = *x;
		*x = *y;
		*y = temp;
	}

	bool isPrime(long long n)
	{
		//OPTIMIZATION check even case once
		if (n % 2 == 0) return false;

		//OPTIMIZATION only need to check odds up until sqrt(n)
		for (long long i = 3; i*i <= n; i+=2) 
		{
			if (n % i == 0) return false;
			else continue;
		}
		return true;
	}

}






