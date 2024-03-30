#include <iostream>
#include<vector>
#include<functional>
#include<math.h>

int main()
{
    setlocale(LC_ALL, "rus");

    std::vector<double> angles{ 30 * 3.1415926 / 180, 60 * 3.1415926 / 180, 90 * 3.1415926 / 180 };

    std::cout << "[Входные данные]:\n" << std::endl;
    for (auto i: angles)
    {
        std::cout << static_cast<int>(round(i * 180 / 3.1415926)) << " deg = " << i << " rad" << std::endl;
    }
    std::vector < std::function<void(double)>>  functions { 
        [&](double angle) { std::cout << "sin: " << sin(angle) << ' '; },
        [&](double angle) { std::cout << "cos: " << cos(angle) << ' '; },
    };
    std::cout << "\n[Выходные данные]:\n" << std::endl;

    for (const auto& angle : angles) {
        std::cout << angle << ": \t";
        for (const auto& function : functions)
            function(angle);
        std::cout << std::endl;
    }
    return 0;
}
