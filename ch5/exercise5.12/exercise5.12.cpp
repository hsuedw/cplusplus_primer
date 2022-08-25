#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    unsigned int ffCnt = 0, flCnt = 0, fiCnt = 0;
    char ch, prech = '\0';
    while (cin >> ch) {
        bool bl = true;
        if (prech == 'f') {
            switch (ch) {
                case 'f':
                    ++ffCnt;
                    bl = false;
                    break;
                case 'l':
                    ++flCnt;
                    break;
                case 'i':
                    ++fiCnt;
                    break;
            }
        }
        if (!bl) {
            prech = '\0';
        } else {
            prech = ch;
        }
    }

    cout << "Number of ff: \t" << ffCnt << endl
         << "Number of fl: \t" << flCnt << endl
         << "Number of fi: \t" << fiCnt << endl;

    return 0;
}
