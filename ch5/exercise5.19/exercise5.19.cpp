#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string rsp;
    do {
        cout << "Please enter two strings: ";

        string s1, s2;
        cin >> s1 >> s2;
        if (s1.size() < s2.size()) {
            cout << "The length of " << s1 << " is shorter than " << s2 << "." << endl;
        } else if (s1.size() > s2.size()) {
            cout << "The length of " << s2 << " is shorter than " << s1 << "." << endl;
        } else {
            cout << "The length of " << s1 << " and " << s2 << " are the same." << endl;
        }
	cout << "More? Enter y or n: ";
        cin >> rsp;
    } while (!rsp.empty() && rsp != "n");

    return 0;
}
