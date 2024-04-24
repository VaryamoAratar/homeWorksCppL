#pragma once

template<class T>
class MyUnique
{
private:
	T* _ptr;
public:
	MyUnique(T* ptr)
	{
		_ptr = ptr;
	};
	~MyUnique()
	{
		delete _ptr;
	};

	MyUnique(const MyUnique& copy) = delete;
	MyUnique& operator = (const MyUnique& copy) = delete;

	T operator * ()
	{
		if (_ptr == nullptr)
		{
			return false;
		}
		return *_ptr;
	}

	T* release()
	{
		T* temp_ptr = this->_ptr;
		this->_ptr = nullptr;
		return temp_ptr;
	}
};

