#pragma once
#include<exception>
#include<iostream>


class SmartArray
{
public:
	SmartArray(int size);
	SmartArray(const SmartArray& copy);
	~SmartArray();


	void add_element(const int& value);

	int get_element(const int& index);

	void print_array();

	SmartArray& operator = (const SmartArray& copy_);

private:
	int size_;
	int size_logical_ = 0;
	int* arr;
};