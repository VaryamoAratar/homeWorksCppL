#include <iostream>
#include <string>
#include <set>
#include <list>
#include <vector>

template<class T>
void print_container(const T& cont)
{
    for (const auto& i : cont)
    {
        std::cout << i << ' ';
    }
};

int main()
{
    std::set<std::string> test_set = { "one", "two", "three", "four" };
    std::list<std::string> test_list = { "one", "two", "three", "four" };
    std::vector<std::string> test_vector = { "one", "two", "three", "four" };

    print_container<std::set<std::string>>(test_set);
    std::cout << std::endl;
    print_container<std::list<std::string>>(test_list);
    std::cout << std::endl;
    print_container<std::vector<std::string>>(test_vector);

    return 0;
}

