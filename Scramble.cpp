// Scrabble
// ����� ����� ����� ������� �����, ������� ������� �� 7 �������� ����.
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

int main()
{
    const std::unordered_map<char, uint8_t> lettersValue{ // ��������� ������ �����
        {'e', 1}, {'a', 1}, {'i', 1}, {'o', 1}, {'n', 1},
        {'r', 1}, {'t', 1}, {'l', 1}, {'s', 1}, {'u', 1},
        {'d', 2}, {'g', 2},
        {'b', 3}, {'c', 3}, {'m', 3}, {'p', 3},
        {'f', 4}, {'h', 4}, {'v', 4}, {'w', 4}, {'y', 4},
        {'k', 5},
        {'j', 8}, {'x', 8},
        {'q', 10}, {'z', 10} };
    const int maxWordLength = 7; // ������������ ����� �����
    int numOfWords;
    std::cin >> numOfWords; // ���� ���-�� ����
    std::cin.ignore();

    std::vector<std::string> words;
    for (int i = 0; i < numOfWords; i++) { // ���� ���� � ���������� � ������ ���� � ���������� �������
        std::string word;
        getline(std::cin, word);
        if (word.length() <= maxWordLength)
            words.push_back(word);
    }
    std::string allowedLetters;
    getline(std::cin, allowedLetters); // ���� ��������� ����

    auto res = std::make_pair<std::string, int>("", 0); // ��������� ������ � ���� <�����, ���������>
    for (auto& word : words) // ��������� ������ �����
    {
        std::unordered_map<char, uint8_t> usedLetters; // ������������ �����, ���������� ������ �����
        for (auto let : allowedLetters)
            usedLetters[let]++; // ������� ������� ��� ����� ������������ ������ �����

        int wordValue = 0; // ���� �������� �����
        for (auto letter : word)
        {
            if (usedLetters[letter] > 0) // ���� ��� ����� ����� ������������
            {
                --usedLetters[letter]; // ��������� ���������� �������������
                wordValue += lettersValue.at(letter); // ���������� �� ���������
            }
            else // ����� ����������, ����������
            {
                wordValue = 0;
                break;
            }
        }
        if (wordValue > res.second) // ���� ���� �������� ����� ������ ����������,
            res = { word, wordValue }; // �� ��������� ���������
    }
    std::cout << res.first << std::endl;
    return 0;
}