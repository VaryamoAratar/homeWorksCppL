﻿#include <iostream>
#include <vector>
#include <algorithm>


//Шаблонный функтор для счетчика и суммы чисел делимых на 3
template<class T>
struct Functor
{
	void operator ()(T n)
	{
		if (!(n % 3))
		{
			count++;
			sum += n;
		}
	}
	T sum{ 0 };
	T count{ 0 };
};

//Шаблонная функция для подсчета суммы чисел делимых на 3
template<class T>
T get_sum(std::vector<T>& v)
{
	Functor<T> s = std::for_each(v.begin(), v.end(), Functor<T>());
	return s.sum;
}

//Шаблонная функция для подсчета чисел делимых на 3
template<class T>
T get_count(std::vector<T>& v)
{
	Functor<T> c = std::for_each(v.begin(), v.end(), Functor<T>());
	return c.count;
}


int main(int argc, char* argv[])
{
	std::vector<int> vec{ 4, 1, 3, 6, 25, 54 };
	std::cout << "[IN]: ";
	for (auto i : vec)
		std::cout << i << ' ';
	std::cout << std::endl;
	std::cout << "[OUT]: get_sum() = " << get_sum(vec) << std::endl;
	std::cout << "[OUT]: get_count() = " << get_count(vec) << std::endl;

	return 0;
}