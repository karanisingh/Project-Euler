//problem17: this file contains the function for the solution for problem 17

/*
* Problem 17: Number Letter Counts
* 
* If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
* 
* If all the numbers from 1 to 1000 were written out in words, how many letters would be used? 
* 
* Solution: 21124
* Time: 0 ms
*/

/*
* Way easier when done with numbers and simple math.
* 
* Find value of 1-9,		| done through pure calculation (36)
* Find value of 10-19,		| done through pure calculation (70)
* Find value of 20-99,		| done easily by finding value of tens digits, adding them up, multiplying by 10 (since x0-x9)
*							| and then adding the value of the ones digits (36)*8 since 2x-9x.  (748)
* 
* Value of 1-99 = 36 + 70 + 748 = 854
* 
* Find value of 100-999		| find values of ones and tens digits (854*9) and ammount of times "hundred" will appear (7*900)
*							| and amount of times "and" will appear (3*891) and value of hundreds digits (36*1000)
* 
* Value of 1-1000 = 854 + (854*9) + (7*900) + (3*891) + (36*100) + 11 = 21124 
*/

/*
* Strategy: calculate how many letters ones digits take up, tens digits, hundreds digits, and then the "hundred and" part
*/

#include "Solutions.h"

int convert(int x)
{
	int sum{ 0 };

	// calculates ones digit's sum if it is not in the teens
	// one, two, six == 3
	// four, five, nine == 4
	// three, seven, eight == 5
	if (x % 100 > 19 || x % 100 < 10)
	{
		int ones{ x % 10 };
		if (ones == 1 || ones == 2 || ones == 6)		sum += 3;
		else if (ones == 4 || ones == 5 || ones == 9)	sum += 4;
		else if (ones == 3 || ones == 7 || ones == 8)	sum += 5;
	}

	//calculates tens digit's sum if it is not in the teens
	if (x % 100 > 19 && x > 19)
	{
		int tens{ (x / 10) % 10 };
		if (tens == 5 || tens == 6 || tens == 4)					sum += 5;
		else if (tens == 2 || tens == 3 || tens == 8 || tens == 9)	sum += 6;
		else if (tens == 7)											sum += 7;
	}
	else if (x % 100 > 9 && x % 100 < 20 && x > 9)    //calculates the teens' values
	{
		int teens{ x % 10 };
		if (teens == 0)													sum += 3;
		else if (teens == 1 || teens == 2)								sum += 6;
		else if (teens == 5 || teens == 6)								sum += 7;
		else if (teens == 3 || teens == 4 || teens == 8 || teens == 9)	sum += 8;
		else if (teens == 7)											sum += 9;
	}
	

	//calculates hundreds digit's sum
	if (x % 100 == 0 && x > 99)     //accomodates for "hundred"
	{
		int hundreds{ x / 100 };
		if (hundreds == 1 || hundreds == 2 || hundreds == 6) sum += 10;
		else if (hundreds == 4 || hundreds == 5 || hundreds == 9) sum += 11;
		else if (hundreds == 3 || hundreds == 7 || hundreds == 8) sum += 12;
	}
	else if ( x > 100 )  //else accomodates for "hundred and"
	{
		int hundreds{ x / 100 };
		if (hundreds == 1 || hundreds == 2 || hundreds == 6) sum += 13;
		else if (hundreds == 4 || hundreds == 5 || hundreds == 9) sum += 14;
		else if (hundreds == 3 || hundreds == 7 || hundreds == 8) sum += 15;
	}

	return sum;
}


int problem17()
{
	int sum{ 30 };						//start off with numbers 1-5, and 1000 accomodated for
	for(int i = 6; i <= 999; ++i)
	{
		sum += convert(i);
	}

	return sum;
}