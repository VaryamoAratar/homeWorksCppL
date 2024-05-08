#include "IniParser.h"

Value::Value(std::string var, int value) : var(var), int_value(value) {};
Value::Value(std::string var, double value) : var(var), double_value(value) {};
Value::Value(std::string var, std::string value) : var(var), str_value(value) {};


IniParser::IniParser(std::string filename) : _filename(filename)
{};
IniParser::~IniParser() {};


IniParser::IniParser(IniParser&& move_copy) noexcept
{ };
IniParser& IniParser::operator = (IniParser&& move_copy) noexcept
{}
;

//template <class T>
int IniParser::get_value(std::string section_value)
{};
