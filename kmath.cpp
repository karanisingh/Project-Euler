//kmath.cpp: holds the definitions for my personal math namespace

#include <cmath>

namespace kmath
{
    //Tried with recursive (do-while loop) first, but almost 3x more efficient with 
    //new method that is specific to this question
    bool isPalindrome(int num) {
        /*
        int cNum = num;
        int digit;
        int reversed{ 0 };

        do
        {
            digit = num % 10;
            reversed = (reversed * 10) + digit;
            num = num / 10;
        } while (num != 0);

        if (reversed == cNum) return true;
        else return false;
        */

        //manually get each digit from the 6 digit number
        if (num / 100000 == num % 10) {
            if ((num % 100000) / 10000 == (num % 100) / 10) {
                if ((num % 10000) / 1000 == (num % 1000) / 100) {
                    return true;
                }
            }
        }
        return false;
        
    }
	
    //returns true if a number is divisible by all the numbers [1,20]
    bool isDivisible(int num)
    {
        //using math, I determined that I only need to check the numbers 11-20
        //If you check in reverse order, then you get through the most numbers quickly
        for (int f = 20; f >= 11; --f) 
        {
            //if not divisible, return false, else keep going
            if (num % f != 0) {
                return false;
            }
        }
        return true;
    }

    //returns the sum of the squars of the first 100 numbers
    int sumSquares(void)
    {
        int sum{ 0 };
        for (int i = 1; i <= 100; ++i) sum += (i * i);
        return sum;
    }

    //returns the square of the sum of the first 100 numbers
    int squareSums(void)
    {
        int sum{ 0 };
        for (int i = 1; i <= 100; ++i) sum += i;
        return sum * sum;
    }


    void sieve(int (&primes)[2000000])
    {
        long i = 2;
        while (i * i <= 2000000)
        {
            if (primes[i] == 0)
            {
                ++i;
                continue;
            }
            long j = 2 * i;
            while (j < 2000000)
            {
                primes[j] = 0;
                j += i;
            }
            ++i;
        }
    }

    //returns the multiplicity of divisors of a number
    int numDivisors(long num)
    {
        int counter{ 0 };

        //lower range since we can count for divisors "> sqrt(num)" while we are counting the first ones
        for (int i = 1; i * i < num; ++i)
        {
            if (num % i == 0) counter += 2;
        }
        //check if num is a square
        if (pow(std::floor(sqrt(num)), 2) == num) ++counter;
        return counter;
    }
}






