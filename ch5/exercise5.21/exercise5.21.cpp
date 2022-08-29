#include <iostream>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    bool isRepeated = false;
    string currWord, prevWord;
    while (cin >> currWord) {
        if (!isupper(currWord[0])) {
            continue;
        }
        if (currWord == prevWord) {
            isRepeated = true;
            cout << currWord << " is duplicated in succession." << endl;;
            break;
        }
        prevWord = currWord;

    }
    if (!isRepeated) {
        cout << "There is no words repeated in succession." << endl;
    }

    return 0;
}
