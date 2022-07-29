#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout << "Please enter a string: " << endl;

    string input;
    getline(cin, input);
    if (!input.empty()) {
        cout << "The string you have entered: " << input << endl;
	/*
	 * When we use auto&, the compiler infers the type of c to be char.
	 * Therefore, after we replace atuo with char, the output remains
	 * the same with previous exercise.
	 */
        for (char& c : input) {
            c = 'X';
        }
	cout << "Your string has been changed to " << input << "." << endl;
    } else {
        cout << "No data has been entered." << endl;
    }

    return 0;
}
