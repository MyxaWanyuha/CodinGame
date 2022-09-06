// Temperatures
// Написать температуру, которая ближе  всего к 0, при -5 и 5 написать 5
#include <iostream>
#include <cmath>
#include <limits>

int main()
{
    int tempsCount;
    std::cin >> tempsCount; std::cin.ignore();
    if (tempsCount == 0)
    {
        std::cout << 0; // если температур нет, вывожим 0 и завершаем выполнение
        return 0;
    }

    int result = std::numeric_limits<int>::max(); // инициализация результата максимальной температурой
    int sign = 1;
    for (int i = 0; i < tempsCount; i++)
    {
        int t; // next temperature ranging from -273 to 5526
        std::cin >> t; std::cin.ignore();

        if (std::abs(result) > std::abs(t)) // новая температура ближе к нулю, то обновляем результат
        {
            sign = t < 0 ? -1 : 1;
            result = std::abs(t);
        }
        else if (std::abs(result) == std::abs(t) && t > 0) // температуры равны по модулю, но нам нужно вывести положительный знак
        {
            sign = 1;
        }
    }

    std::cout << sign * result << '\n';
    return 0;
}