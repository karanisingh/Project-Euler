//kmath.cpp: holds the definitions for my personal math namespace

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


    int sumSquares(void)
    {
        int sum{ 0 };
        for (int i = 1; i <= 100; ++i) sum += (i * i);
        return sum;
    }


    int squareSums(void)
    {
        int sum{ 0 };
        for (int i = 1; i <= 100; ++i) sum += i;
        return sum * sum;
    }
}






