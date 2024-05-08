#include "IniParser.h"

int main()
{
    setlocale(LC_ALL, "rus");

    std::cout << "Hello World!\n";

    std::ifstream in("sample.ini");
    if (!in.is_open())
    {
        std::cout << "file not open" << std::endl;
    }
    std::string file_in{};
    std::string section{};

    while (!in.eof())
    {
        std::string str_var{};
        std::string str_value{};
        int int_value{};
        double double_value{};
        std::string value{};

        std::getline(in, file_in);
        if (file_in.empty())
        {
            continue;
        }
        if (file_in.find(';') != std::string::npos)
        {
            auto it = std::find(file_in.begin(), file_in.end(), ';');
            file_in.erase(it, file_in.end());
        }

        if (file_in.find("[Section") != std::string::npos)
        {
            auto it = std::remove_if(file_in.begin(), file_in.end(), [](const char& file_in) { return file_in == ' '; });
            file_in.erase(it, file_in.end());
            section = file_in;
        }

        if (file_in.find('=') != std::string::npos)
        {
            auto it = std::find(file_in.begin(), file_in.end(), '=');
            for (auto i = file_in.begin(); i != it; i++)
            {
                str_var += *i;
            }

            for (auto i = it + 1; i != file_in.end(); i++)
            {
                str_value += *i;
            }
            try
            {
                    double_value = std::stod(str_value);
                    if (!fmod(double_value, 1))
                    {
                        int_value = double_value;
                }
            }
            catch (const std::exception& e)
            {
                value = str_value;
            }

        }

        std::cout << "строка: " << file_in << std::endl;

    }
    in.close();
    return 0;

}