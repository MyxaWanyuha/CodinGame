#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

void InitUsedLetters(map<char, uint8_t>& m, std::string& allowedLetters)
{
    for (auto let : allowedLetters)
        m[let]++;
}

int main()
{
    map<char, uint8_t> lettersValue{
        {'e', 1}, {'a', 1}, {'i', 1}, {'o', 1}, {'n', 1},
        {'r', 1}, {'t', 1}, {'l', 1}, {'s', 1}, {'u', 1},
        {'d', 2}, {'g', 2},
        {'b', 3}, {'c', 3}, {'m', 3}, {'p', 3},
        {'f', 4}, {'h', 4}, {'v', 4}, {'w', 4}, {'y', 4},
        {'k', 5},
        {'j', 8}, {'x', 8},
        {'q', 10}, {'z', 10} };
    const int maxWordLength = 7;

    int numOfWords;
    cin >> numOfWords; cin.ignore();

    vector<string> words;
    for (int i = 0; i < numOfWords; i++) {
        string word;
        getline(cin, word);
        if (word.length() <= maxWordLength)
            words.push_back(word);
    }
    string allowedLetters;
    getline(cin, allowedLetters);

    auto res = make_pair<string, int>("", 0);
    for (auto& word : words)
    {
        map<char, uint8_t> usedLetters;
        InitUsedLetters(usedLetters, allowedLetters);
        int wordValue = 0;
        for (auto letter : word)
        {
            if (usedLetters[letter] > 0)
            {
                usedLetters[letter]--;
                wordValue += lettersValue[letter];
            }
            else
            {
                wordValue = 0;
                break;
            }
        }
        if (wordValue > res.second)
            res = { word, wordValue };
    }
    cout << res.first << endl;
    return 0;
}
