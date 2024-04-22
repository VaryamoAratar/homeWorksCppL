#include <iostream>
#include <set>
#include <string>
#include <exception>

struct CountedСharacters
{
public:
	CountedСharacters(char val, int count) : _val(val), _count(count) {};
	int _count;
	char _val;

	bool operator < (CountedСharacters s) const
	{
		if (s._count == _count)
			return s._val < _val;
		return s._count < _count;
	}
};

int main(int argc, char* argv[])
{
	try
	{
		//объявляем строку для чтения с консоли
		std::string str_in;
		std::cout << "[IN]: ";
		//запрашиваем строку у пользователя
		std::getline(std::cin, str_in);
		//Перегоняем строку в контейнер char'ов
		std::multiset<char> symbol;
		for (auto i = 0; i < str_in.length(); i++)
		{
			symbol.insert(str_in[i]);
		}
		//Проверяем заполнение контейнера
		if (symbol.empty())
		{
			throw std::runtime_error("Multyset is Empty!");
		}
		//объявляем контейнер посчитаннх символов
		std::set<CountedСharacters> сounted_сharacters;
			std::cout << "[OUT]: " << std::endl;
		//перегоняем символы с подсчитанным числом, отсеиваем дубликаты
		for (auto i : symbol)
		{
			сounted_сharacters.insert(CountedСharacters(i, symbol.count(i)));
		}
		//выводим результат
		for (auto i = сounted_сharacters.begin(); i != сounted_сharacters.end(); i++)
		{
			std::cout << i->_val << ' ' << i->_count << std::endl;
		}
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	return 0;
}