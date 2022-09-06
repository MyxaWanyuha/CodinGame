// There is no Spoon - Episode 1
// ����� ��������� ������ ������ �� ������� � ������ ����� �� �������,
// ���� ������ �� ���������� �������� -1 -1, ����� �� ����������
// �����: "0 0 1 0 0 1" ������ ��� ����� - ������� ������, ������ - ������ ������, ��������� - ������ �����
#include <iostream>
#include <string>

std::string TwoNumToString(int n1, int n2)
{
    return std::to_string(n1) + ' ' + std::to_string(n2);
}

std::string CheckLine(int i, int j, int length, char* field, int fieldWidth, bool isBottom)
{
    // field[i][j] == *(field + i * length + j)
    while (++i != length) // ���� �� �� ����� �� ������� ����
    {
        if (isBottom && *(field + i * fieldWidth + j) == '0') // ���� �� ��������� ������ ����� � ��� �������
            return ' ' + TwoNumToString(j, i); // ���������� �� ����������
        else if (!isBottom && *(field + j * fieldWidth + i) == '0') // ���� �� ��������� ������ ������ � ��� �������
            return ' ' + TwoNumToString(i, j); // ���������� �� ����������
    }
    return ' ' + TwoNumToString(-1, -1); // ������ �� ����������
}

int main()
{
    int width; // the number of cells on the X axis
    std::cin >> width; std::cin.ignore();
    int height; // the number of cells on the Y axis
    std::cin >> height; std::cin.ignore();
    auto field = new char[height * width]; // ���� ������� �� "0" - "������ ����" � "." - "������ ���"

    for (int i = 0; i < height; i++) {
        std::string line;
        getline(std::cin, line); // width characters, each either 0 or .
        for (int j = 0; j < width; j++)
        {
            *(field + i * width + j) = line.c_str()[j]; // ������ � �������
        }
    }

    std::string output;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (*(field + i * width + j) == '.') continue; // ���� ������ ����������, ����������
            output = TwoNumToString(j, i); // ������ ��� �����, ���������� ������� ������
            output += CheckLine(j, i, width, field, width, false); // ���������� ���������� ������ ������
            output += CheckLine(i, j, height, field, width, true); // ���������� ���������� ������ �����
            std::cout << output << std::endl; // �����
        }
    }

    delete[] field;
    return 0;
}