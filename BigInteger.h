//BigInteger.h: Header file for my BigInteger class
#pragma once
#include <string>
#include <vector>

/*
* This BigInteger holds an integer's value in a vector.
*/
class BigInteger
{
public:
	BigInteger();
	BigInteger(std::string& val);
	BigInteger operator=(const BigInteger& b);
	BigInteger operator*(const int& i);
	void initializeValue(std::string& newVal);
	std::string getValue() const;
	std::vector<int> getContainer() const;
	

private:
	std::vector<int> container;
	int digits;
};

