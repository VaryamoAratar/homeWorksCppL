#pragma once

class SmartArray
{
public:
	SmartArray(int size);
	~SmartArray();

	void add_element(const int& value);

	int get_element(const int& index);

private:
	int size_;
	int size_logical_ = 0;
	int* arr;
};