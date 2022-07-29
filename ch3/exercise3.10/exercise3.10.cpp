#include <iostream>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string input;

    getline(cin, input);
    if (!input.empty()) {
        cout << "Your input (len = " << input.size() << "): "  << input << endl;
        cout << "Your input has been modified: " ;

        decltype(input.size()) i = 0, j = 0;
        while (j < input.size()) {
            if (!ispunct(input[j])) {
                input[i++] = input[j++];
            } else {
                ++j;
	    }
        }
	if (i < input.size()) {
            input.resize(i);
	}
        cout << "Your input has been modified (len = " << input.size() <<"): "  << input << endl;
    } else {
        cout << "No data has been entered." << endl;
    }

    return 0;
}
