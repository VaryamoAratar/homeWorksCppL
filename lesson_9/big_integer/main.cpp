﻿#include "BigInteger.h"

int main()
{
	try
	{
		auto num1 = std::move(BigInteger("123456"));
		auto num2 = BigInteger("544");
		auto sum = std::move(num1 + num2);
		std::cout << "Hello World!\n";
		std::cout << sum << std::endl;
		auto num3 = BigInteger("1234");
		auto num4 = std::move(BigInteger("23"));
 		auto mult = std::move(num3 * num4);
		std::cout << mult << std::endl;

		BigInteger s;
		s = BigInteger("123");
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	return 0;
}

