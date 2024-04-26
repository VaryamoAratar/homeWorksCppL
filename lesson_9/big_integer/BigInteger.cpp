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
		if (size_lhs >= size_rhs)
		{
			out = result_sum(this->_v, rhs._v);
		}
		else
		{
			out = result_sum(rhs._v, this->_v);
		}
		_v = std::move(out);
		return *this;
	}

	BigInteger& BigInteger::operator*(const BigInteger& rhs)
	{
		int size_lhs = this->_v.size();
		int size_rhs = rhs._v.size();
		std::vector<int> out;
		if (size_lhs >= size_rhs)
		{
			out = result_mult(this->_v, rhs._v);
		}
		else
		{
			out = result_mult(rhs._v, this->_v);
		}
		_v = std::move(out);
		return *this;
	}


	std::vector<int> BigInteger::result_sum(const std::vector<int>& lhs, const std::vector<int>& rhs)
	{
		int size_lhs = lhs.size();
		int size_rhs = rhs.size();
		int num_tmp = 0;
		std::vector<int> tmp_v(size_lhs + 1);
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

			if (!j)
			{
				for (i = (i - 1); i >= 0; i--)
				{
					result[i] = lhs[i] + num_tmp;
					num_tmp = 0;
				}
			}
			if (i == 0 && (lhs[i] + rhs[j] + num_tmp) >= 10)
			{
				for (int i = (tmp_v.size() - 1), j = (result.size() - 1); i >= ((tmp_v.size() - 1) - (result.size() - 1)), j >= 0; i--, j--)
				{
					tmp_v[i] = result[j];
				}
				tmp_v[0] = num_tmp;
				result = std::move(tmp_v);
			}
		}
		return result;
	}
	std::vector<int> BigInteger::result_mult(const std::vector<int>& lhs, const std::vector<int>& rhs)
	{
		int size_lhs = lhs.size();
		int size_rhs = rhs.size();
		int num_tmp = 0;
		std::vector<int> tmp_v(size_lhs);
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
				if (j != (size_rhs - 1) && !i)
				{
					tmp_v.push_back(0);
				}
			}
			result = result_sum(tmp_v, result);
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

