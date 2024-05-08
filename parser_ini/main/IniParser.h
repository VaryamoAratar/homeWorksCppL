#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>
#include <exception>
#include <map>
#include <unordered_map>

struct Value
{
	Value(std::string var, int value);
	Value(std::string var, double value);
	Value(std::string var, std::string value);

	std::string var;
	int int_value = NULL;
	double double_value = NULL;
	std::string str_value = NULL;
};

class IniParser
{
public:
	IniParser(std::string filename);
	~IniParser();

	IniParser(const IniParser& copy) = delete;
	IniParser& operator = (const IniParser& copy) = delete;

	IniParser(IniParser&& move_copy) noexcept;
	IniParser& operator = (IniParser&& move_copy) noexcept;

	//template <class T>
	int get_value(std::string section_value);

private:
	std::string _filename;
	std::string _var;
	std::string _section;
	std::unordered_map <std::string, Value> _section_value;
};

