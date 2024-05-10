#include "IniParser.h"

int main()
{
    setlocale(LC_ALL, "rus");

    std::cout << "Hello World!\n";
	try
	{
    IniParser parser("sample.ini");
	auto value = parser.get_value<int>("Section1.var5");
	std::cout << value << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "End!\n";

    return 0;

}