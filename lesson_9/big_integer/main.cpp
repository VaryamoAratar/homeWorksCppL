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
		auto num1 = BigInteger("123456");
		auto num2 = BigInteger("544");
		auto sum = num1 + num2;
		std::cout << "Hello World!\n";
		std::cout << sum << std::endl;
		auto num3 = BigInteger("1234");
		auto num4 = BigInteger("23");
 		auto mult = num3 * num4;
		std::cout << mult << std::endl;
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	return 0;
}

