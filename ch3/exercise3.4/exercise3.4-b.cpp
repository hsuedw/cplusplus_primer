#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    string str1, str2;

    cout << "Please enter two strings: " << endl;
    cin >> str1 >> str2;
    if (str1.size() == str2.size()) {
        cout << "The two strings have the same length." << endl;
    } else if (str1.size() > str2.size()) {
        cout << str1 << " is longer." << endl;
    } else {
        cout << str2 << " is longer." << endl;
    }

    return 0;
}
