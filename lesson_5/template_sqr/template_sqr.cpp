#include <iostream>
#include <vector>


template<class T>
T mySqr(T x)
{
	return x * x;
}

template<class T>
std::vector<T> mySqr(std::vector<T> x)
{
	for (auto& i : x)
	{
		i *= i;
	}

	return x;
}


int main()
{

	int in = 4;

	std::cout << "[IN]: " << in << "\n[OUT]: " << mySqr(in) << std::endl;

	std::vector<double> inVector{ -1.2, 4, 8.2 };
	std::cout << "[IN]: ";
	for (auto i : inVector)
		std::cout << i << ' ';
	std::cout << "\n[OUT]: ";
	for (auto i : mySqr(inVector))
		std::cout << i << ' ';

	return 0;
}