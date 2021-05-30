//problem15.cpp: this file contains the function to the solution for problem 15

/*
* Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
* 
* How many such routes are ther through a 20x20 grid?
* 
* Solution: 137846528820
* Time: 41 sec
*/

 
/*
* much simpler to use mathematics to determine a solution.
* my original thinking was to find the number of combinations of "downs" and "rights" where there have to be 20 downs and 20 rights.
* this can be easily solved using combinations: 40! / 20! * 20! = 137846528820
*/

//algorithmic computation is very heavy

//recursively count all paths starting from the destination
long long problem15(long long r = 20, long long c = 20)
{
    //if we are in the upmost row or leftmost column, then there is only one path leading to the end
    if (r == 0 || c == 0) return 1;

    //if we are one row in, then this algorithm calculates how many paths to the end
    else if (r == 1 || c == 1)
    {
        if (r != 1) return r + 1;
        else return c + 1;
    }

    //if we are two rows in, then this algorithm calculates how many paths to the end
    else if (r == 2 || c == 2)
    {
        if (r != 2) return problem15(r - 1, c) + (r + 1);
        else return problem15(r, c - 1) + (c + 1);
    }

    //if we are on the middle diagonal, we only need to calculate how many paths from one step and multiply it by 2
    if (r == c) return 2 * (problem15(r, c - 1));

    //recursively find for one step to the left, and onne step up
    return problem15(r - 1, c) + problem15(r, c - 1);
}