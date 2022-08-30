#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;

int main()
{
    int a, b;

    while (true) {
        cout << "Please input two integers: " << endl;
        cin >> a >> b;
        try {
             if (b == 0) {
                 throw runtime_error("The divisor must be non zero.");
            }
            cout << a  << " / " << b << " = " << a / b << endl;
        } catch (runtime_error err) {
            cout << err.what() << endl
                 << "Try again? Enter y or n" << endl;
            char c;
            cin >> c;
	    if (!cin || c == 'n') {
                break;
	    }
        }
    }

    return 0;
}
