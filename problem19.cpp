//problem19.cpp: this file contains the function for the solution for problem 19

/*
* Problem 19: Counting Sundays
* 
* You are given the following information, but you may prefer to do some research for yourself.
*	~ 1 Jan 1900 was a Monday
*	~ 30 Days: Apr, Jun, sep, Nov
*	~ 31 Days: Jan, Mar, May, Jul, Aug, Oct, Dec
*	~ Feb: 28, or 29 on leap years (year divisible by four, && year divisible by 400 if year is a century
* 
* How many Sundayas fell on the first of the month month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
* 
* Solution: 171
* Time: 0 ms
*/

int problem19()
{
	int numSundays{ 0 };
	int firstDay{ 2 };

	//iterate through the years.
	for (int year = 1901; year <= 2000; ++year)
	{
		//check if it is a leap year
		bool isLeapYear = (year % 4 == 0 || year % 400 == 0) ? true : false;

		//iterate through the months
		for (int month = 1; month <= 12; ++month)
		{
			//if first day is a sunday, increment num of sundays
			if (firstDay == 0) ++numSundays;

			//calculate the next month's first day.
			switch (month)
			{
			case 1:
				firstDay = (firstDay + 31) % 7;
				break;
			case 2:
				if (isLeapYear) firstDay = (firstDay + 29) % 7;
				else firstDay = (firstDay + 28) % 7;
				break;
			case 3:
				firstDay = (firstDay + 31) % 7;
				break;
			case 4:
				firstDay = (firstDay + 30) % 7;
				break;
			case 5:
				firstDay = (firstDay + 31) % 7;
				break;
			case 6:
				firstDay = (firstDay + 30) % 7;
				break;
			case 7:
				firstDay = (firstDay + 31) % 7;
				break;
			case 8:
				firstDay = (firstDay + 31) % 7;
				break;
			case 9:
				firstDay = (firstDay + 30) % 7;
				break;
			case 10:
				firstDay = (firstDay + 31) % 7;
				break;
			case 11:
				firstDay = (firstDay + 30) % 7;
				break;
			case 12:
				firstDay = (firstDay + 31) % 7;
				break;
			}
		}
	}

	return numSundays;
}