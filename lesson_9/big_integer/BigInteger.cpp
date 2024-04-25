#include "BigInteger.h"

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

	BigInteger& BigInteger::operator=(BigInteger&& from) noexcept
	{
		if (this != &from)
		{
			_v.clear();
			_v = from._v;
		}

		return *this;
	}

	BigInteger& BigInteger::operator+(const BigInteger& rhs)
	{
		int size_lhs = this->_v.size();
		int size_rhs = rhs._v.size();
		std::vector<int> out;
		if (size_lhs > size_rhs)
		{
			out = result_sum(this->_v, rhs._v);
		}
		else
		{
			out = result_sum(rhs._v, this->_v);
		}
		std::swap(this->_v, out);
		return *this;
	}

	BigInteger& BigInteger::operator*(int rhs)
	{

	}


	std::vector<int> BigInteger::result_sum(const std::vector<int>& lhs, const std::vector<int>& rhs)
	{
		std::vector<int> tmp_v;
		std::vector<int> result;
		int size_lhs = lhs.size();
		int size_rhs = rhs.size();
		int num_tmp = 0;

		tmp_v.resize(size_lhs);
		result.resize(size_lhs);
		for (int i = (size_lhs - 1), j = (size_rhs - 1); i >= (size_lhs - size_rhs), j >= 0; i--, j--)
		{
			tmp_v[i] = rhs[j];
		}
		for (int i = size_lhs - 1; i >= 0; i--)
		{
			result[i] = (lhs[i] + tmp_v[i]) % 10 + num_tmp;
			if ((lhs[i] + tmp_v[i] + num_tmp) >= 10 && i != 0)
			{
				result[i] = result[i] % 10;
				num_tmp = 1;
			}
			else num_tmp = 0;
		}
		return result;
	}

BigInteger::BigInteger(std::string in)
{
	for (auto i = begin(in); i != end(in); i++)
	{
		_v.push_back(*i - '0');
	}
}
BigInteger::BigInteger()
{
	_v.clear();
}
BigInteger::BigInteger(const BigInteger& copy)
{
	_v.resize(copy._v.size());
	for (int i = 0; i < _v.size(); i++)
	{
		_v[i] = copy._v[i];
	}
}
BigInteger::BigInteger(BigInteger&& copy) noexcept
{
	_v = copy._v;
}
BigInteger::~BigInteger()
{
}

