//problem18.cpp: this file contains the function for the solution for problem 18

/*
* Problem 18: Maximum Path Sum 1
* 
* Find the maximum total from top to bottom of the triangle below by only moving to adjacent numbers on the row below
* 
*                      75
*                     95 64
*                   17 47 82
*                  18 35 87 10
*                20 04 82 47 65
*               19 01 23 75 03 34
*             88 02 77 73 07 63 67
*            99 65 04 28 06 16 70 92
*          41 41 26 56 83 40 80 70 33
*         41 48 72 33 47 32 37 16 94 29
*       53 71 44 65 25 43 91 52 97 51 14
*      70 11 33 28 77 73 17 78 39 68 17 57
*    91 71 52 38 17 14 91 43 58 50 27 29 48
*   63 66 04 68 89 53 67 30 73 16 69 87 40 31
* 04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
* 
* 
* Solution: 1074
* Time: 0 ms
*/

/*
* Strategy: use a greedy algorithm-
* 
* Decompose the bottom two rows into one row which represents the greatest sum that can be achieved from a path
* 
* Keep doing this until the greatest sum is in the first element of the first row ( index(0,0) )
*/

#include "Solutions.h"

int problem18()
{
	//the triangle
	int triangle [15][15] =
	{
		{75,														0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{95, 64,													0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{17, 47, 82,												0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{18, 35, 87, 10,											0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{20, 4, 82, 47, 65,											0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{19, 1, 23, 75, 3, 34,										0, 0, 0, 0, 0, 0, 0, 0, 0},
		{88, 2, 77, 73, 7, 63, 67,									0, 0, 0, 0, 0, 0, 0, 0},
		{99, 65, 4, 28, 6, 16, 70, 92,								0, 0, 0, 0, 0, 0, 0},
		{41, 41, 26, 56, 83, 40, 80, 70, 33,						0, 0, 0, 0, 0, 0},
		{41, 48, 72, 33, 47, 32, 37, 16, 94, 29,					0, 0, 0, 0, 0},
		{53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14,				0, 0, 0, 0},
		{70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57,			0, 0, 0},
		{91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48,		0, 0},
		{63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31,		0},
		{4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23},
	};

	

	for (int i = 13; i >= 0; --i)							//iterate through the rows starting from the second to bottom one going up
	{
		for (int j = i; j >= 0; --j)						//iterate through the values in each row
		{
			int left = triangle[i + 1][j];					//value of the left child of the value we are on
			int right = triangle[i + 1][j + 1];				//value of the right child of the value we are on

			//replace the current vaue with the sum of its greatest path
			(left > right) ? triangle[i][j] += left: triangle[i][j] += right;		
		}
	}

	//return the sum of the greatest path
	return triangle[0][0];
	
}