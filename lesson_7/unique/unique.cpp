#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> v = { 1, 1, 2, 5, 6, 1, 2, 4 };
    std::cout << "[IN]: ";
    for (auto i : v)
    {
        std::cout << i << ' ';
    }
    std::cout << "\n[OUT]: ";

    std::sort(v.begin(), v.end());
    auto itr = std::unique(v.begin(), v.end());
    v.erase(itr, v.end());
    for (auto i : v)
    {
        std::cout << i << ' ';
    }
    return 0;
}

