#include <iostream>
#include <exception>

template<class T>
class MyVector
{
public:
	MyVector(T size) : _size(size), _arr( new T[size] {0}) {};
	~MyVector()
	{
		if (_arr)
			delete[] _arr;
	};
	MyVector(const MyVector& copy)
	{
		_size = copy._size;
		_logical_size = copy._logical_size;
		_arr = new T[copy._size]{ 0 };
		for (size_t i = 0; i < copy._logical_size; i++)
		{
			_arr[i] = copy._arr[i];
		}
	}
	MyVector& operator = (const MyVector& copy)
	{
		if (this != &copy)
		{
			delete[] _arr;
			_size = copy._size;
			_logical_size = copy._logical_size;
			_arr = new T[copy._size]{ 0 };
			for (size_t i = 0; i < copy._logical_size; i++)
			{
				_arr[i] = copy._arr[i];
			}
		}

	};
	T at(const int& index)
	{
		if (index < 0 || index >= _logical_size)
		{
			throw std::runtime_error("index out of range");
		}
		else
			return _arr[index];
	};
	void push_back(const T& value)
	{
		if (_logical_size > _size - 1)
		{
			_size *= 2;
			T* arr_tmp = new T[_size] {0};
			for (int i = 0; i < _logical_size; i++)
			{
				arr_tmp[i] = _arr[i];
			}
			delete[] _arr;
			_arr = arr_tmp;
		}
		_arr[_logical_size] = value;
		_logical_size++;
	};
	int size() { return _logical_size; };
	int capacity() { return _size; }
	
private:
	T* _arr = nullptr;
	int _logical_size = 0;
	int _size;
};


int main()
{
	try
	{
		MyVector<int> vec(2);
		std::cout << vec.capacity() << std::endl;
		std::cout << vec.size() << std::endl;
		vec.push_back(5);
		vec.push_back(3);
		vec.push_back(512);
		vec.push_back(54);
		vec.push_back(54);

		std::cout << vec.capacity() << std::endl;
		std::cout << vec.size() << std::endl;

		std::cout << vec.at(0) << std::endl;
		std::cout << vec.at(1) << std::endl;

	}

	catch (const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	return 0;
}
