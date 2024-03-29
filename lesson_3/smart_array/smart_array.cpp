#include<iostream>
#include<exception>

class SmartArray
{
public:
	SmartArray(int size);
	~SmartArray();

	void add_element(const int& value)
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

	int get_element(const int& index)
	{
		if (index < 0 || index >= size_)
		{
			throw std::exception("index out of range");
		}
		else
			return arr[index];
	};

private:
	int size_;
	int size_logical_ = 0;
	int* arr;
};

SmartArray::SmartArray(int size) :size_{ size }, arr{ new int[size] {0} }
{
}

SmartArray::~SmartArray()
{
	delete[] arr;
}

int main()
{
	setlocale(LC_ALL, "rus");

	try
	{
		SmartArray arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		arr.add_element(15);
		std::cout << arr.get_element(10) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}
	return 0;
}