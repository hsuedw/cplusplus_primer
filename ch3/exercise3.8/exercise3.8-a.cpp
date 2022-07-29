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
        for (string::size_type i = 0; i < input.size(); ++i) {
            input[i] = 'X';
        }
	cout << "Your string has been changed to " << input << "." << endl;
    } else {
        cout << "No data has been entered." << endl;
    }

    return 0;
}
