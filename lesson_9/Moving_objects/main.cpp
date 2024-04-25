#include <iostream>
#include <vector>


template<class T>
void move_objects(T& one, T& two)
{
    two = std::move(one);
};

int main()
{
    std::vector <std::string> one = { "test_string1", "test_string2" };
    std::vector <std::string> two;

    move_objects<std::vector<std::string>>(one, two);

    std::cout << two[0] << ' ' << two[1] << std::endl;

    return 0;
}

