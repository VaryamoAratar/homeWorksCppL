#pragma once
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <exception>

class BigInteger
{

	public:
		BigInteger(std::string in);
		BigInteger();
		BigInteger(const BigInteger& copy);
		BigInteger(BigInteger&& copy) noexcept;
		~BigInteger();


		BigInteger& operator=(const BigInteger& from);
		BigInteger& operator=(BigInteger&& from) noexcept;
		BigInteger& operator+(const BigInteger& rhs);
		BigInteger& operator*(const BigInteger& rhs);

		friend std::ostream& operator << (std::ostream& os, const BigInteger& rhs);

	private:
		std::vector<int> result_sum(const std::vector<int>& lhs, const std::vector<int>& rhs);
		std::vector<int> _v;
		std::vector<int> result_mult(const std::vector<int>& lhs, const std::vector<int>& rhs);

};