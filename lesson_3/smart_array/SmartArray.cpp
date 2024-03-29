#include "SmartArray.h"
#include<exception>

	void SmartArray::add_element(const int& value)
	{
		if (size_logical_ > size_ - 1)
		{
			size_ *= 2;
			int* arr_tmp = new int[size_] {0};
			for (int i = 0; i < size_logical_; i++)
			{
				arr_tmp[i] = arr[i];
			}
			delete[] arr;
			arr = arr_tmp;
		}
		arr[size_logical_] = value;
		size_logical_++;
	};

	int SmartArray::get_element(const int& index)
	{
		if (index < 0 || index >= size_)
		{
			throw std::exception("index out of range");
		}
		else
			return arr[index];
	};

	SmartArray::SmartArray(int size) :size_{ size }, arr{ new int[size] {0} }
	{
	}

	SmartArray::~SmartArray()
	{
		delete[] arr;
	}
