#include "SmartArray.h"

int main()
{
	setlocale(LC_ALL, "rus");

	try
	{
		SmartArray arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		arr.add_element(15);
		std::cout << arr.get_element(10) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}
	return 0;
}