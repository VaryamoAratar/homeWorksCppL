#pragma once

template<class T>
class MyUnique
{
private:
	T* _ptr = new T;
public:
	MyUnique(T* ptr)
	{
		_ptr = ptr;
	};
	~MyUnique()
	{
		std::cout << "Call destructor" << std::endl;
		delete _ptr;
	};

	MyUnique(const MyUnique& copy) = delete;
	MyUnique& operator = (const MyUnique& copy) = delete;

	T operator * ()
	{
		return *_ptr;
	};

	T* release()
	{
		_ptr = nullptr;
		return _ptr;
	}
};

