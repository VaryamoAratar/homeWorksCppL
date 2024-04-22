#include <iostream>
#include <set>
#include <exception>

int main(int argc, char* argv[])
{
	try
	{
		std::cout << "[IN]: " << std::endl;
		//запрашиваем у пользователя количество элементов
		int num = 0;
		std::cin >> num;

		//объявляем контейнер для удаления дубликатов
		std::set<int> remov_dupl;

		//вводим значения
		for (auto i = 0; i < num; i++)
		{
			int in;
			std::cin >> in;
			remov_dupl.insert(in);
		}
		//проверяем заполнение контейнера
		if (remov_dupl.empty())
		{
			throw std::runtime_error("remov_dupl is Empty!");
		}
		std::cout << "[OUT]: " << std::endl;
		//выводим результат
		for (auto i = remov_dupl.rbegin(); i != remov_dupl.rend(); i++)
		{
			std::cout << *i << std::endl;
		}
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "invalid value" << std::endl;
	}
	return 0;
}