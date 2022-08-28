#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    char c;
    bool isRepeated = false;
    string currWord, prevWord;
    while (cin.get(c)) {
        if (c == ' ') {
            if (currWord == prevWord) {
                cout << currWord << " is repeated in succession." << endl;
                isRepeated = true;	
                break;
            }
            prevWord = currWord;
            currWord.clear();
        } else {
            currWord.push_back(c);
        }
    }
    if (!isRepeated) {
        cout << "There is no words repeated in succession." << endl;
    }

    return 0;
}
