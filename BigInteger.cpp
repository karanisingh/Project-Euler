//BigInteger.cpp: this file contains the implementation for a BigInteger class
#include "BigInteger.h"

/*
* Default constructor
* 
* Initializes the value as 0
*/
BigInteger::BigInteger()
{
	container.push_back(0);
	digits = 0;
}

/*
* Overloaded constructor
* 
* Initializes the value as the string passed in 
* 
* Argument must be a string representing an integer
*/
BigInteger::BigInteger(std::string& val)
{
	//iterates through each character in the string and adds it to the vector
	initializeValue(val);
}

/*
* Overloaded "=" operator method
* 
* Copies the container of one bigint to the caller, updates digits
*/
BigInteger BigInteger::operator=(const BigInteger& b)
{
	container = b.getContainer();
	digits = container.size();
	return *this;
}

/*
* Overloaded "*" operator method
* 
* Multiplies the caller bigint by a number
* 
* Currently only compatable with argument "2"
*/
BigInteger BigInteger::operator*(const int& i)
{

	int carryOver{ 0 };								//to hold the carry over for each digit's calculation
	for (int i = container.size()-1; i >= 0; --i)	//iterates from least to most significant digit
	{
		int sum{ container[i] * 2 + carryOver };    //calculates the sum of multiplying a digit by 2

		container[i] = sum % 10;                    //replaces digit with correct value
		carryOver = sum / 10;                       //dtermines carry over for the next digit
	}
	
	if (carryOver == 1)								//if the last carry over is 1, then we must push a 1 onto the front of the vector
	{
		++digits;
		container.insert(container.begin(),1);
	}


	return *this;									//return the updated bigint
}

/*
* Initializes the value the bigint holds
* 
* Argument must be a string representing an integer
*/
void BigInteger::initializeValue(std::string& newVal)
{
	container.clear();					//clears the current container

	for (auto x : newVal)				//iterates through the string and updates the container
	{
		container.push_back(x - '0');
	}
	digits = newVal.length();			//updats the digits field
}

/*
* Getter function for the string form of the value of the big int
*/
std::string BigInteger::getValue() const
{
	std::string val = "";			//temporary string
	for (auto x : container)		//iterates through container and adds values to string
	{
		val += std::to_string(x);
	}
	return val;
}

/*
* Returns the vector holding the value of the bigint
*/
std::vector<int> BigInteger::getContainer() const
{
	return container;
}

