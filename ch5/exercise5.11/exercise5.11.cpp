#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    unsigned int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    unsigned int spaceCnt = 0, tabCnt = 0, newlineCnt = 0;
    char ch;
    while (cin.get(ch)) {
        switch (ch) {
            case 'a':
            case 'A':
                ++aCnt;
                break;
            case 'e':
            case 'E':
                ++eCnt;
                break;
            case 'i':
            case 'I':
                ++iCnt;
                break;
            case 'o':
            case 'O':
                ++oCnt;
                break;
            case 'u':
            case 'U':
                ++uCnt;
                break;
            case ' ':
                ++spaceCnt;
                break;
            case '\t':
                ++tabCnt;
                break;
            case '\n':
                ++newlineCnt;
                break;
        }
    }

    cout << "Number of vowel a: \t" << aCnt << endl
         << "Number of vowel e: \t" << eCnt << endl
         << "Number of vowel i: \t" << iCnt << endl
         << "Number of vowel o: \t" << oCnt << endl
         << "Number of space: \t" << spaceCnt << endl
         << "Number of tab: \t\t" << tabCnt << endl
         << "Number of new line: \t" << newlineCnt << endl;

    return 0;
}
