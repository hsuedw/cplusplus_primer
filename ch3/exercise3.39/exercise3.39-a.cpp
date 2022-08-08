#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::cin;

int main()
{
    string s1, s2;
    cout << "Please enter two strings: " << endl;
    cin >> s1 >> s2;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;

    if (s1 < s2) {
        cout << "s2 is greater than s1." << endl;
    } else if (s2 < s1) {
        cout << "s1 is greater than s2." << endl;
    } else {
        cout << "s1 and s2 are the equal." << endl;
    }

    return 0;
}
