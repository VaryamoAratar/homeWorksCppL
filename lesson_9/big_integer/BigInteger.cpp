#include "BigInteger.h"
	//ќператор присваивани€
	BigInteger& BigInteger::operator=(const BigInteger& from)
	{
		if (this != &from)
		{
			_v.clear();
			_v.resize(from._v.size());
			for (int i = 0; i < _v.size(); i++)
			{
				_v[i] = from._v[i];
			}
		}

		return *this;
	}
	//ќператор перемещающего присваивани€
	BigInteger& BigInteger::operator=(BigInteger&& from) noexcept
	{
		if (this != &from)
		{
			_v.clear();
			_v = from._v;
		}

		return *this;
	}
	//ќператор сложени€
	BigInteger& BigInteger::operator+(const BigInteger& rhs)
	{
		//объ€вл€ем и инициализируем размеры слагаемых
		int size_lhs = this->_v.size();
		int size_rhs = rhs._v.size();
		//объ€вл€ем выходной вектор
		std::vector<int> out;
		if (size_lhs >= size_rhs)
		{
			// передаем вектора в метод суммы. ѕервым идет вектор большего размера
			out = result_sum(this->_v, rhs._v);
		}
		else
		{
			out = result_sum(rhs._v, this->_v);
		}
		// пермещаем результат в исходный вектор
		_v = std::move(out);
		return *this;
	}

	BigInteger& BigInteger::operator*(const BigInteger& rhs)
	{
		//объ€вл€ем и инициализируем размеры слагаемых
		int size_lhs = this->_v.size();
		int size_rhs = rhs._v.size();
		//объ€вл€ем выходной вектор
		std::vector<int> out;
		if (size_lhs >= size_rhs)
		{
			// передаем вектора в метод произведени€. ѕервым идет вектор большего размера
			out = result_mult(this->_v, rhs._v);
		}
		else
		{
			out = result_mult(rhs._v, this->_v);
		}
		// пермещаем результат в исходный вектор
		_v = std::move(out);
		return *this;
	}

	//метод суммы
	std::vector<int> BigInteger::result_sum(const std::vector<int>& lhs, const std::vector<int>& rhs)
	{
		//объ€вл€ем и инициализируем размеры слагаемых
		int size_lhs = lhs.size();
		int size_rhs = rhs.size();
		//объ€влем число в уме
		int num_tmp = 0;
		//ќбъ€вл€ем вектор дл€ расчета
		std::vector<int> result(size_lhs);

		for (int i = (size_lhs - 1), j = (size_rhs - 1); i >= 0, j >= 0; i--, j--)
		{
			result[i] = lhs[i] + rhs[j] + num_tmp;
			if (result[i] >= 10 && i != 0)
			{
				num_tmp = result[i] / 10;
				result[i] = result[i] % 10;
			}
			else num_tmp = 0;
			//≈сли закончились элементы второго массива
			if (!j)
			{
				for (i = (i - 1); i >= 0; i--)
				{
					result[i] = lhs[i] + num_tmp;
					num_tmp = 0;
				}
			}
			//есил первый элемент результурующего вектора больше 9
			if (i == 0 && num_tmp)
			{
				result.push_back(0);
				for (int i = (result.size() - 1), j = (result.size() - 2); i >= 1, j >= 0; i--, j--)
				{
					result[i] = result[j];
				}
				result[0] = num_tmp;
			}
		}
		return result;
	}
	//метод произведени€
	std::vector<int> BigInteger::result_mult(const std::vector<int>& lhs, const std::vector<int>& rhs)
	{
		//объ€вл€ем и инициализируем размеры слагаемых
		int size_lhs = lhs.size();
		int size_rhs = rhs.size();
		//объ€влем число в уме
		int num_tmp = 0;
		//вектор поэлементного произведени€
		std::vector<int> tmp_v(size_lhs);
		//вектор суммы произведений
 		std::vector<int> result(size_lhs);

		for (int j = size_rhs - 1; j >= 0; j--)
		{
			for (int i = (size_lhs - 1); i >= 0; i--)
			{
				tmp_v[i] = lhs[i] * rhs[j] + num_tmp;
				if (tmp_v[i] >= 10 && i != 0)
				{
					num_tmp = tmp_v[i] / 10;
					tmp_v[i] = tmp_v[i] % 10;
				}
				else num_tmp = 0;

				if (i == 0 && num_tmp)
				{
					tmp_v.push_back(0);
					for (int i = (tmp_v.size() - 1), j = (tmp_v.size() - 2); i >= 1, j >= 0; i--, j--)
					{
						tmp_v[i] = tmp_v[j];
					}
					tmp_v[0] = num_tmp;
					num_tmp = 0;
				}
				//в конце каждого следующего произведени€ добавл€ем пустой элемент дл€ правильного сложени€
				if (j != (size_rhs - 1) && !i)
				{
					tmp_v.push_back(0);
				}
			}
			//сумма призведений
			result = result_sum(tmp_v, result);
		}
		return result;
	}
//конструктор принимает число в виде строки
BigInteger::BigInteger(std::string in)
{
	for (auto i = begin(in); i != end(in); i++)
	{
		_v.push_back(*i - '0');
	}
}
//конструктор по умолчанию
BigInteger::BigInteger()
{}
// конструктор копировани€
BigInteger::BigInteger(const BigInteger& copy)
{
	_v.resize(copy._v.size());
	for (int i = 0; i < _v.size(); i++)
	{
		_v[i] = copy._v[i];
	}
}
//конструктор перемещающего копировани€
BigInteger::BigInteger(BigInteger&& copy) noexcept
{
	_v = copy._v;
}
//деструктор
BigInteger::~BigInteger()
{
	_v.clear();
}

std::ostream& operator << (std::ostream& os, const BigInteger& rhs)
{
	for (auto i : rhs._v)
		std::cout << i;
	return os;
}


