// Scrabble
// Нужно найти самое дорогое слово, которое состоит из 7 заданных букв.
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

int main()
{
    const std::unordered_map<char, uint8_t> lettersValue{ // стоимость каждой буквы
        {'e', 1}, {'a', 1}, {'i', 1}, {'o', 1}, {'n', 1},
        {'r', 1}, {'t', 1}, {'l', 1}, {'s', 1}, {'u', 1},
        {'d', 2}, {'g', 2},
        {'b', 3}, {'c', 3}, {'m', 3}, {'p', 3},
        {'f', 4}, {'h', 4}, {'v', 4}, {'w', 4}, {'y', 4},
        {'k', 5},
        {'j', 8}, {'x', 8},
        {'q', 10}, {'z', 10} };
    const int maxWordLength = 7; // максимальная длина слова
    int numOfWords;
    std::cin >> numOfWords; // ввод кол-ва слов
    std::cin.ignore();

    std::vector<std::string> words;
    for (int i = 0; i < numOfWords; i++) { // ввод слов и добавление в вектор слов с допустимой длинной
        std::string word;
        getline(std::cin, word);
        if (word.length() <= maxWordLength)
            words.push_back(word);
    }
    std::string allowedLetters;
    getline(std::cin, allowedLetters); // ввод доступных букв

    auto res = std::make_pair<std::string, int>("", 0); // результат храним в паре <слово, стоимость>
    for (auto& word : words) // проверяем каждое слово
    {
        std::unordered_map<char, uint8_t> usedLetters; // используемые буквы, количество каждой буквы
        for (auto let : allowedLetters)
            usedLetters[let]++; // считаем сколько раз можно использовать каждую букву

        int wordValue = 0; // цена текущего слова
        for (auto letter : word)
        {
            if (usedLetters[letter] > 0) // если эту букву можно использовать
            {
                --usedLetters[letter]; // уменьшаем количество использований
                wordValue += lettersValue.at(letter); // прибавляем ее стоимость
            }
            else // слово невалидное, пропускаем
            {
                wordValue = 0;
                break;
            }
        }
        if (wordValue > res.second) // если цена текущего слова больше результата,
            res = { word, wordValue }; // то обновляем результат
    }
    std::cout << res.first << std::endl;
    return 0;
}