#include <iostream>
#include <unordered_set>
#include <set>
#include <map>
#include <string>
#include <exception>

struct MyStruct
{
	char val;
	int count;
};

int main(int argc, char* argv[])
{
	try
	{
		std::string str_in;
		std::cout << "[IN]: ";
		std::getline(std::cin, str_in);
		std::unordered_multiset<char> symbol;
		for (auto i = 0; i < str_in.length(); i++)
		{
			symbol.insert(str_in[i]);
		}
		if (symbol.empty())
		{
			throw std::runtime_error("Multyset is Empty!");
		}

		for (auto i = symbol.begin(); i!= symbol.end(); i++)
		{
			std::cout << *i << ' ' << symbol.count(*i) << std::endl;
		}
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	return 0;
}