#include "SmartArray.h"
	// ���������� �������� � ������
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
	// ��������� �������� �� �������
	int SmartArray::get_element(const int& index)
	{
		if (index < 0 || index >= size_)
		{
			throw std::exception("index out of range");
		}
		else
			return arr[index];
	};
	// ����� �������� ������� � �������
	void SmartArray::print_array()
	{
		for (int i = 0; i < size_logical_; i++)
		{
			std::cout << arr[i] << ' ';
		}
		for (int i = size_logical_; i < size_; i++)
		{
			std::cout << '_' << ' ';
		}
		std::cout << std::endl;
	}
	// ����������� �� ���������
	SmartArray::SmartArray(int size) :size_{ size }, arr{ new int[size] {0} }
	{
	}
	// ����������� ����������� ��� �������� ������� ������
	SmartArray::SmartArray(const SmartArray& copy)
	{
		size_ = copy.size_;
		size_logical_ = copy.size_logical_;
		arr = new int[copy.size_] {0};
		for (size_t i = 0; i < copy.size_logical_; i++)
		{
		arr[i] = copy.arr[i];
		}
	}
	// ���������� �� ���������
	SmartArray::~SmartArray()
	{
		delete[] arr;
	}
	// ���������� ��������� ������������ ��� ����������� ������ ������� � ������
	SmartArray& SmartArray::operator = (const SmartArray& copy_)
	{
		delete[] arr;
		size_ = copy_.size_;
		size_logical_ = copy_.size_logical_;
		arr = new int[copy_.size_] {0};
		for (size_t i = 0; i < copy_.size_logical_; i++)
		{
			arr[i] = copy_.arr[i];
		}
		return *this;
	}
