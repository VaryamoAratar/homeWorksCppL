#include <iostream>
#include "MyUnique.h"

int main()
{   
    MyUnique<int> ptr(new int(5));
    std::cout << *ptr << std::endl;
    auto left = ptr.release();
    std::cout << *ptr << std::endl;
    std::cout << *left << std::endl;

    return 0;
}