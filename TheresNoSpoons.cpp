// There is no Spoon - Episode 1
// Ќужно проверить €чейку справа от текущей и €чейку снизу от текущей,
// если €чейка не существуют написать -1 -1, иначе их координаты
// вывод: "0 0 1 0 0 1" первые два числа - текуща€ €чейка, вторые - €чейка справа, последние - €чейка снизу
#include <iostream>
#include <string>

std::string TwoNumToString(int n1, int n2)
{
    return std::to_string(n1) + ' ' + std::to_string(n2);
}

std::string CheckLine(int i, int j, int length, char* field, int fieldWidth, bool isBottom)
{
    // field[i][j] == *(field + i * length + j)
    while (++i != length) // пока мы не вышли за пределы пол€
    {
        if (isBottom && *(field + i * fieldWidth + j) == '0') // если мы провер€ем €чейку снизу и она валидна
            return ' ' + TwoNumToString(j, i); // возвращаем ее координаты
        else if (!isBottom && *(field + j * fieldWidth + i) == '0') // если мы провер€ем €чейку справа и она валидна
            return ' ' + TwoNumToString(i, j); // возвращаем ее координаты
    }
    return ' ' + TwoNumToString(-1, -1); // €чейка не существует
}

int main()
{
    int width; // the number of cells on the X axis
    std::cin >> width; std::cin.ignore();
    int height; // the number of cells on the Y axis
    std::cin >> height; std::cin.ignore();
    auto field = new char[height * width]; // поле состоит из "0" - "€чейка есть" и "." - "€чейки нет"

    for (int i = 0; i < height; i++) {
        std::string line;
        getline(std::cin, line); // width characters, each either 0 or .
        for (int j = 0; j < width; j++)
        {
            *(field + i * width + j) = line.c_str()[j]; // запись в таблицу
        }
    }

    std::string output;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (*(field + i * width + j) == '.') continue; // если €чейка невалидна€, пропускаем
            output = TwoNumToString(j, i); // первые два числа, координаты текущей €чейки
            output += CheckLine(j, i, width, field, width, false); // прибавл€ем координаты €чейки справа
            output += CheckLine(i, j, height, field, width, true); // прибавл€ем координаты €чейки снизу
            std::cout << output << std::endl; // вывод
        }
    }

    delete[] field;
    return 0;
}