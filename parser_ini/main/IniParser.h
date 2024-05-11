#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>
#include <exception>
#include <map>
#include <unordered_map>
#include <clocale>



class IniParser
{
public:
	IniParser(std::string filename);
	~IniParser();
    //��������� ����������� � ������������
	IniParser(const IniParser& copy) = delete;
	IniParser& operator = (const IniParser& copy) = delete;
    // ������ ������������ ����������� � ������������
	IniParser(IniParser&& move_copy) noexcept;
	IniParser& operator = (IniParser&& move_copy) noexcept;

    //��������� ������� ��� �������� �����
	template <class T>
    T get_value(std::string section_var)
    {

        std::string section{ "[" };
        std::string var{};
        //�������� ��� ������ � �������� ����������
        //�������� �������� �� "."
        auto it_dot = std::find(section_var.begin(), section_var.end(), '.');
        //�������� �������� ������
        for (auto i = section_var.begin(); i != it_dot; i++)
        {
            section += *i;
        }
        section += ']';
        // �������� �������� ����������
        for (auto i = it_dot + 1; i != section_var.end(); i++)
        {
            var += *i;
        }
        //��������� ������� ������, ���� ��� �����, �� ������� ������ ������
        if (!_section_value.count(section))
        {
            std::cout << "Available sections:" << std::endl;
            for (const auto& i : _section_value)
            {
                std::cout << i.first << std::endl;
            }
            throw std::invalid_argument("The requested section was not found!");
        }
        auto out_var = _section_value[section];
        //��������� ������� ����������, ���� ��� �����, �� ������� ������ ����������
        if (!out_var.count(var))
        {
            std::cout << "Available variable:" << std::endl;
            for (const auto& i : out_var)
            {
                std::cout << i.first << std::endl;
            }
            throw std::invalid_argument("The variable you requested was not found!");
        }
        std::string out_value = out_var[var];
        //��������� ������� ����������� �������� � �������� ����������,
        //���� ����, �� ����������� ���������� � �������������� ����
        if (std::all_of(out_value.begin(), out_value.end(), [](auto a) { return (a == ' ' || a == '.' || (a > 47 && a < 58)); }))
        {
            if (typeid(T) == typeid(double))
            {
                if (out_value.find('.') != std::string::npos)
                {
                    //���� ������ �������, ������ "." �� ",", ��� ��� ��� ������� ������ ���������� �������� -> ","
                    if (setlocale(LC_ALL, NULL) == "Russian_Russia.1251")
                    {
                        int ptr = out_value.find('.');
                        out_value.replace(ptr, 1, ",");
                    }
                    return std::stod(out_value);
                }
                //���� ��� ��������, �� ��� �� double, ����������� �������������� ����������
                else
                {
                    std::string t = typeid(T).name();
                    std::string err = "!ERROR!\nThe requested variable does not match the expected type [" + t + "].\nType of variable [int].";
                    throw std::invalid_argument(err);
                }

            }
            else if (typeid(T) == typeid(float))
            {
                if (out_value.find('.') != std::string::npos)
                {
                    //���� ������ �������, ������ "." �� ",", ��� ��� ��� ������� ������ ���������� �������� -> ","
                    if (setlocale(LC_ALL, NULL) == "Russian_Russia.1251")
                    {
                        int ptr = out_value.find('.');
                        out_value.replace(ptr, 1, ",");
                    }
                    return std::stof(out_value);
                }
                //���� ��� ��������, �� ��� �� float, ����������� �������������� ����������
                else
                {
                    std::string t = typeid(T).name();
                    std::string err = "!ERROR!\nThe requested variable does not match the expected type [" + t + "].\nType of variable [int].";
                    throw std::invalid_argument(err);
                }

            }
            else if (typeid(T) == typeid(int))
            {
                if (out_value.find('.') == std::string::npos)
                {
                    return std::stoi(out_value);
                }
                //���� ���� ��������, �� ��� �� int, ����������� �������������� ����������

                else
                {
                    std::string t = typeid(T).name();
                    std::string err = "!ERROR!\nThe requested variable does not match the expected type [" + t + "].\nType of variable [double] or [float].";
                    throw std::invalid_argument(err);
                }
            }
        }
        else throw std::invalid_argument("!ERROR!\nThe requested variable does not match the expected type.");
    }
    //������������� ������� ��� String
    template<>
    std::string get_value(std::string section_var)
    {
        std::string section{ "[" };
        std::string var{};

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
            throw std::invalid_argument("The requested section was not found!");
        }
        auto out_var = _section_value[section];
        if (!out_var.count(var))
        {
            std::cout << "Available variable:" << std::endl;
            for (const auto& i : out_var)
            {
                std::cout << i.first << std::endl;
            }
            throw std::invalid_argument("The variable you requested was not found!");
        }
        std::string out_value = out_var[var];
        //���� �������� ���������� �������� ������ ����� ���� int ��� double, �� ����������� ��������������� ����������
        if (std::all_of(out_value.begin(), out_value.end(), [](auto a) { return (a == ' ' || a == '.' || (a > 47 && a < 58)); }))
        {
            if (out_value.find('.') != std::string::npos)
            {
                std::string err = "!ERROR!\nThe requested variable does not match the expected type [string].\nType of variable [double].";
                throw std::invalid_argument(err);
            }
            else
            {
                std::string err = "!ERROR!\nThe requested variable does not match the expected type [string].\nType of variable [int].";
                throw std::invalid_argument(err);
            }
        }
        else return out_value;
    }

private:
	std::string _filename;
	std::string _var;
	std::string _value;
	std::string _section;
	std::unordered_map <std::string, std::string> _var_value;
	std::unordered_map <std::string, std::unordered_map <std::string, std::string>> _section_value;
};

