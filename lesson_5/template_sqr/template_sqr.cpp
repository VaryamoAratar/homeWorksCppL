#include <iostream>
#include <vector>

//Шаблонная функция возведения в квадрат
template<class T>
T mySqr(const T& x)
{
	return x * x;
}

//Шаблонная функция возведения в квадрат вектора
template<class T>
std::vector<T> mySqr(const std::vector<T>& x)
{
	std::vector<T> y(x.size());
	for (auto i = 0; i < x.size(); i++)
	{
		y[i] = x[i] * x[i];
	}
	return y;
}


int main(int argc, char* argv[])
{
	//инициализируем переменную, например типа INT = 5
	int in = 4;
	std::cout 
		//выводим исходное значение
		<< "[IN]: " << in 
		//выводим квадрат значения
		<< "\n[OUT]: " << mySqr(in) << std::endl;

	//инициализируем вектор типа DOUBLE
	std::vector<double> inVector{ -1.2, 4, 8.2 };
	std::cout << "[IN]: ";
	//выводим вектор исходных значений
	for (auto i : inVector)
		std::cout << i << ' ';
	//выводим вектор квадратов исходных значений
	std::cout << "\n[OUT]: ";
	for (auto i : mySqr(inVector))
		std::cout << i << ' ';

	return 0;
}