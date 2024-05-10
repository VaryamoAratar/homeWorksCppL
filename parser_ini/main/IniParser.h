#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>
#include <exception>
#include <map>
#include <unordered_map>

//struct VarValue
//{
//	std::string _var;
//	std::string _value;
//};

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
	std::string _value;
	std::string _section;
	std::unordered_map <std::string, std::string> _var_value;
	std::unordered_map <std::string, std::unordered_map <std::string, std::string>> _section_value;
};

