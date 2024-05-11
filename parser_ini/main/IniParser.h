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
    //запрещаем копирование и присваивание
	IniParser(const IniParser& copy) = delete;
	IniParser& operator = (const IniParser& copy) = delete;
    // только перемещающее копирование и присваивание
	IniParser(IniParser&& move_copy) noexcept;
	IniParser& operator = (IniParser&& move_copy) noexcept;

    //Шаблонная функция для числовых типов
	template <class T>
    T get_value(std::string section_var)
    {

        std::string section{ "[" };
        std::string var{};
        //считваем имя секции и название переменной
        //получаем итератор на "."
        auto it_dot = std::find(section_var.begin(), section_var.end(), '.');
        //собираем название секции
        for (auto i = section_var.begin(); i != it_dot; i++)
        {
            section += *i;
        }
        section += ']';
        // собираем название переменной
        for (auto i = it_dot + 1; i != section_var.end(); i++)
        {
            var += *i;
        }
        //проверяем наличие секции, если нет такой, то выводим список секций
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
        //проверяем наличие переменной, если нет такой, то выводим список переменных
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
        //проверяем наличие посторонних символов в значении переменной,
        //если есть, то выбрасываеи исключение о несоответствии типа
        if (std::all_of(out_value.begin(), out_value.end(), [](auto a) { return (a == ' ' || a == '.' || (a > 47 && a < 58)); }))
        {
            if (typeid(T) == typeid(double))
            {
                if (out_value.find('.') != std::string::npos)
                {
                    //если локаль русская, меняем "." на ",", так как для русской локали десятичный делитель -> ","
                    if (setlocale(LC_ALL, NULL) == "Russian_Russia.1251")
                    {
                        int ptr = out_value.find('.');
                        out_value.replace(ptr, 1, ",");
                    }
                    return std::stod(out_value);
                }
                //если нет делителя, то это не double, выбрасываем соответсвующее исключение
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
                    //если локаль русская, меняем "." на ",", так как для русской локали десятичный делитель -> ","
                    if (setlocale(LC_ALL, NULL) == "Russian_Russia.1251")
                    {
                        int ptr = out_value.find('.');
                        out_value.replace(ptr, 1, ",");
                    }
                    return std::stof(out_value);
                }
                //если нет делителя, то это не float, выбрасываем соответсвующее исключение
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
                //если есть делитель, то это не int, выбрасываем соответсвующее исключение

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
    //специализация шаблона для String
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
        //если значение переменной содержит только числа типа int или double, то выбрасываем соответствующее исключение
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

