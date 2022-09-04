#include <string>
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

bool hasCapitalLetters (const string &s )
{
    for (const auto & c : s) {
        if (isupper(c)) {
            return true;
        }
    }
    return false;
}


void toLowerCases(string &s)
{
    for (auto &c : s) {
        c |= 0x20;
    }
}

int main()
{
    string s;
    cout << "Please enter a string: ";
    cin >> s;
    if (hasCapitalLetters(s)) {
        cout << "This string contains capital letters." << endl;

	toLowerCases(s);
	cout << "Change all the letters to lowercases: "  << s << endl;
    } else {
        cout << "This string does not contain any capital letters." << endl;
    }

    return 0;
}
