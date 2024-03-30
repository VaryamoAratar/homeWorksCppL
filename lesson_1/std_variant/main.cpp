#include<iostream>
#include<variant>
#include<vector>

std::variant<int, std::string, std::vector<int>> get_variant() {
    std::srand(std::time(nullptr));
    int random_variable = std::rand() % 3;

    std::variant<int, std::string, std::vector<int>> result;
    switch (random_variable)
    {
    case 0:
        result = 5;
        break;
    case 1:
        result = "string";
        break;
    case 2:
        result = std::vector<int>{ 1, 2, 3, 4, 5 };
        break;
    default:
        break;
    }
    return result;
}

int main()
{
    setlocale(LC_ALL, "rus");

    auto value = get_variant();
    bool is_int = std::holds_alternative<int>(value);
    bool is_string = std::holds_alternative<std::string>(value);
    bool is_vector = std::holds_alternative<std::vector<int>>(value);

    if (is_int)
    {
        auto val_out = std::get < int > (value);
        std::cout << val_out * 2;
    }
    else if (is_string)
    {
        auto val_out = std::get < std::string > (value);
        std::cout << val_out;
    }
    else
    {
        auto val_out = std::get < std::vector<int> >(value);
        for (auto i : val_out)
        {
            std::cout << i << ' ';
        }
    }
    return 0;
}