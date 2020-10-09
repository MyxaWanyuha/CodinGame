#include <iostream>
#include <string>
using namespace std;

string TwoNumToString(int n1, int n2)
{
    return to_string(n1) + ' ' + to_string(n2);
}

string CheckLine(int i, int j, int length, char* field, int fieldWidth, bool isBottom)
{
    while (++i != length)
    {
        if (isBottom && *(field + i * fieldWidth + j) == '0')
            return ' ' + TwoNumToString(j, i);
        else if (!isBottom && *(field + j * fieldWidth + i) == '0')
            return ' ' + TwoNumToString(i, j);
    }
    return ' ' + TwoNumToString(-1, -1);
}

int main()
{
    int width;
    cin >> width; cin.ignore();
    int height;
    cin >> height; cin.ignore();
    auto field = new char[height * width];

    for (int i = 0; i < height; i++) {
        string line;
        getline(cin, line);
        for (int j = 0; j < width; j++)
        {
            *(field + i * width + j) = line.c_str()[j];
        }
    }

    string output;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (*(field + i * width + j) == '.') continue;
            output = TwoNumToString(j, i);
            output += CheckLine(j, i, width, field, width, false);
            output += CheckLine(i, j, height, field, width, true);
            cout << output << endl;
        }
    }

    delete[] field;
    return 0;
}