#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::cin;

#define MAXLEN (128)

int main()
{
    char s1[MAXLEN], s2[MAXLEN];
    cout << "Please enter two strings: " << endl;
    cin >> s1 >> s2;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;

    int result = strcmp(s1, s2);
    if (result < 0) {
        cout << "s2 is greater than s1." << endl;
    } else if (result > 0) {
        cout << "s1 is greater than s2." << endl;
    } else {
        cout << "s1 and s2 are the equal." << endl;
    }

    return 0;
}
