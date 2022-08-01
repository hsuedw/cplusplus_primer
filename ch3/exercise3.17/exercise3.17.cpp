#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<string> wordList;
    string word;
    while (cin >> word) {
        wordList.push_back(word);
    }

    for (auto &w : wordList) {
        for (auto &c : w) {
            c = toupper(c);
        }
    }

    for (int i = 0; i < wordList.size(); ++i) {
        if (i == 0 || i % 8 != 0) {
            cout << wordList[i] << " ";
        } else {
            cout << endl;
        }
    }

    return 0;
}
