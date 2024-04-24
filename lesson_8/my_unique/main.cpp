#include <iostream>
#include "MyUnique.h"

int main()
{   
    MyUnique<int> ptr(new int(5));
    std::cout << *ptr << std::endl;
    ptr.release();

    return 0;
}