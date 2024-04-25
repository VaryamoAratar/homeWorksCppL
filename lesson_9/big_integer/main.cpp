#include <iostream>
#include "BigInteger.h"

std::ostream& operator << (std::ostream& os, const BigInteger& rhs)
{
	for (auto i : rhs._v)
		std::cout << i;
	return os;
}

int main()
{
	try
	{
		auto num1 = BigInteger("12345");
		auto num2 = BigInteger("123456");
		auto sum = num1 + num2;
		std::cout << "Hello World!\n";
		std::cout << sum;
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	return 0;
}

