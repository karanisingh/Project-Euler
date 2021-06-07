//problem14.cpp: this file contains the function for the solution for problem 14

/*
* Problem 14: Longest Collatz Sequence
* 
* Using the Collats sequence, which starting number, under one million, produces the longest chain?
* 
* Solution: 837799
* Time: 449 ms
*/

/*
Original Strategy: Keep an array that holds each starting number's length and use it to calculate others

int* arr = new int[1000000];

//recursively calculates the length of the collatz seqeuence of a number
int collatz(std::int64_t x)
{
	if (x == 1)							return 1;
	if (arr[x] != 0 && x < 1000000)		return arr[x];
	if (x % 2 == 0)
	{
		if (arr[x] != 0 && x < 1000000)	return (arr[x / 2] + 1);
		else							return (collatz(x / 2) + 1);
	}
	else								return (collatz(3 * x + 1) + 1);
}

int problem14()
{
	//fill the array with zeros
	std::fill(arr, arr + 1000000, 0);
	int gStart{ 2 };
	arr[1] = 1;
	arr[2] = 2;
	//std::cout << "here ";

	//fill in the arry with the chains' lengths up to 1000000
	for (std::int64_t i = 3; i < 1000000; ++i)
	{
		collatz(i);
		//if (arr[i] > arr[gStart]) gStart = i;
		//std::cout << i << " ";
	}
	//std::cout << "here ";
	return arr[3];
}
*/


/*
* New strategy: realized that original strategy did not account for values larger than 1000000, so converted it to while loop, then converted it to for loop based on length
* 
* Surprisingly viable
*/
int problem14()
{
	/*
	//part of the original strategy
	//fill the array with zeros
	std::fill(arr, arr + 1000000, 0);
	int gStart{ 2 };
	arr[1] = 1;
	arr[2] = 2;
	//std::cout << "here ";

	//fill in the arry with the chains' lengths up to 1000000
	for (std::int64_t i = 3; i < 1000000; ++i)
	{
		collatz(i);
		//if (arr[i] > arr[gStart]) gStart = i;
		//std::cout << i << " ";
	}
	//std::cout << "here ";
	return arr[3];
	*/
	int answer{ 0 };
	int gLength{ 1 };

	for (int i = 2; i < 1000000; ++i)
	{
		int currentLength{ 1 };
		for (long temp = i; temp > 1; ++currentLength)
		{
			if (temp % 2 == 0)	temp = temp / 2;
			else				temp = (3 * temp) + 1;
		}

		if (currentLength > gLength)
		{
			gLength = currentLength;
			answer = i;
		}
	}

	return answer;
}
