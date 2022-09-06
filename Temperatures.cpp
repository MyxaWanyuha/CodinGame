// Temperatures
// �������� �����������, ������� �����  ����� � 0, ��� -5 � 5 �������� 5
#include <iostream>
#include <cmath>
#include <limits>

int main()
{
    int tempsCount;
    std::cin >> tempsCount; std::cin.ignore();
    if (tempsCount == 0)
    {
        std::cout << 0; // ���� ���������� ���, ������� 0 � ��������� ����������
        return 0;
    }

    int result = std::numeric_limits<int>::max(); // ������������� ���������� ������������ ������������
    int sign = 1;
    for (int i = 0; i < tempsCount; i++)
    {
        int t; // next temperature ranging from -273 to 5526
        std::cin >> t; std::cin.ignore();

        if (std::abs(result) > std::abs(t)) // ����� ����������� ����� � ����, �� ��������� ���������
        {
            sign = t < 0 ? -1 : 1;
            result = std::abs(t);
        }
        else if (std::abs(result) == std::abs(t) && t > 0) // ����������� ����� �� ������, �� ��� ����� ������� ������������� ����
        {
            sign = 1;
        }
    }

    std::cout << sign * result << '\n';
    return 0;
}