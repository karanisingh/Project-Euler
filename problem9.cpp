//problem9.cpp: this file contains the function for the solution for problem 9

/*
* Problem 9: Special Pythagorean Triplet
* 
* A Pythagorean triplet is a set of three natural numbers, a < b < c, for which
* 
* a^2 + b^2 = c^2
* 
* There exists exactly one Pythagorean triplet for which a + b + c = 1000.
* Find the product abc
* 
* Solution: 31875000
* Time: 421 ms
*/

/*
* This can be done without the use of programming by using algebra and perimeter of triangles
*/

#include <iostream>

//brute force, check every number. because it's only 1000 no need to really optimize.
int problem9()
{
	int c{};
	for (int a = 1; a < 1000; ++a)
	{
		for (int b = 1; b < 1000; ++b)
		{
			for (int c = 1; c < 1000; ++c)
			{
				if (a + b + c != 1000) continue;
				if (a * a + b * b == c * c) return a * b * c;
			}
			
		}
	}
	return 0;
}
