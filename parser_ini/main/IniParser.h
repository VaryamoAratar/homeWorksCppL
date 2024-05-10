#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>
#include <exception>
#include <map>
#include <unordered_map>



class IniParser
{
public:
	IniParser(std::string filename);
	~IniParser();

	IniParser(const IniParser& copy) = delete;
	IniParser& operator = (const IniParser& copy) = delete;

	IniParser(IniParser&& move_copy) noexcept;
	IniParser& operator = (IniParser&& move_copy) noexcept;

	template <class T>
    T get_value(std::string section_var)
    {
        std::string section{ "[" };
        std::string var{};
        T value{};

        auto it_dot = std::find(section_var.begin(), section_var.end(), '.');
        for (auto i = section_var.begin(); i != it_dot; i++)
        {
            section += *i;
        }
        section += ']';
        for (auto i = it_dot + 1; i != section_var.end(); i++)
        {
            var += *i;
        }
        if (!_section_value.count(section))
        {
            std::cout << "Available sections:" << std::endl;
            for (const auto& i : _section_value)
            {
                std::cout << i.first << std::endl;
            }
            throw std::invalid_argument("The section was not found!");
        }
        auto out_var = _section_value[section];
        if (!out_var.count(var))
        {
            std::cout << "Available variable:" << std::endl;
            for (const auto& i : out_var)
            {
                std::cout << i.first << std::endl;
            }
            throw std::invalid_argument("The variable was not found!");
        }
        std::string out_value = out_var[var];

        if (typeid(value) == typeid(double))
        {
            return std::stod(out_value);
        }
        else if (typeid(value) == typeid(int))
        {
            if (out_value.find('.') == std::string::npos)
            {
                return std::stoi(out_value);
            }
            else throw std::invalid_argument("the variable not found");
        }
        else if (typeid(value) == typeid(std::string))
        {
            return 0;
        }
        else throw std::invalid_argument("the variable not found");
    }

private:
	std::string _filename;
	std::string _var;
	std::string _value;
	std::string _section;
	std::unordered_map <std::string, std::string> _var_value;
	std::unordered_map <std::string, std::unordered_map <std::string, std::string>> _section_value;
};

