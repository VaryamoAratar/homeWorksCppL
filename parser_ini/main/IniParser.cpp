#include "IniParser.h"

IniParser::IniParser(std::string filename) : _filename(filename)
{
    std::ifstream in_ini_file(_filename);
    if (!in_ini_file.is_open())
    {
        throw "File is not open";
    }
    std::string str_from_file{};
    int count_str{ 0 };

    while (!in_ini_file.eof())
    {
        count_str++;
        std::string str_var{};
        std::string str_value{};
        _var = "";
        _value = "";
        //считываем всю строку из ини файла
        std::getline(in_ini_file, str_from_file);
        //если строка пустая, то пропускаем цикл
        if (str_from_file.empty())
        {
            continue;
        }
        //если в строке только пробелы, то пропускаем цикл
        if (std::all_of(str_from_file.begin(), str_from_file.end(), isspace))
        {
            continue;
        }
        //если в строке есть ";" удаляем все комментарии после этого знака
        if (str_from_file.find(';') != std::string::npos)
        {
            auto it_comment = std::find(str_from_file.begin(), str_from_file.end(), ';');
            str_from_file.erase(it_comment, str_from_file.end());
        }
        //если в строке есть "[", то это название секции, удаляем все пробелы
        if (str_from_file.find('[') != std::string::npos)
        {
            _var_value.clear();
            if (str_from_file.find(' ') != std::string::npos)
            {
            auto it_section = std::remove_if(str_from_file.begin(), str_from_file.end(), [](const char& str_from_file) { return str_from_file == ' '; });
            str_from_file.erase(it_section, str_from_file.end());
            }
            if (str_from_file.find(']') == std::string::npos || (std::find(str_from_file.begin(), str_from_file.end(), ']')) != str_from_file.end() - 1)
            {
                std::string err = "error in the ini file on the line: " + count_str;
                throw std::runtime_error(err);
            }
            _section = str_from_file;
        }
        //если в строке есть "=", то это группа переменная -> значение, делим на 2 части до = и после
        if (str_from_file.find('=') != std::string::npos)
        {
            auto it_var = std::find(str_from_file.begin(), str_from_file.end(), '=');
            for (auto i = str_from_file.begin(); i != it_var; i++)
            {
                str_var += *i;
            }
            //удаляем все пробелы в названии переменной
            if (str_var.find(' ') != std::string::npos)
            {
                auto it_clean = std::remove_if(str_var.begin(), str_var.end(), [](const char& str_var) { return str_var == ' '; });
                str_var.erase(it_clean, str_var.end());
            }
            _var = str_var;
            //значение сохраняем как есть
            for (auto i = it_var + 1; i != str_from_file.end(); i++)
            {
                str_value += *i;
            }
            _value = str_value;
        }
        _var_value[_var] = _value;
        _section_value[_section] = _var_value;
    }
    in_ini_file.close();
};
IniParser::~IniParser() {};


IniParser::IniParser(IniParser&& move_copy) noexcept
{
	_filename = std::move(move_copy._filename);
	_var = std::move(move_copy._var);
	_value = std::move(move_copy._value);
	_section = std::move(move_copy._section);
	_var_value = std::move(move_copy._var_value);
	_section_value = std::move(move_copy._section_value);
};
IniParser& IniParser::operator = (IniParser&& move_copy) noexcept
{
	if (this != &move_copy)
	{
	_filename = std::move(move_copy._filename);
	_var = std::move(move_copy._var);
	_value = std::move(move_copy._value);
	_section = std::move(move_copy._section);
	_var_value = std::move(move_copy._var_value);
	_section_value = std::move(move_copy._section_value);
	}
	return *this;
};

