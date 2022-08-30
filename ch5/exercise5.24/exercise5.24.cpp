#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;

int main()
{
    int a, b;
    cout << "Please input two integers: " << endl;
    cin >> a >> b;
    if (b == 0) {
        throw runtime_error("The divisor must be non zero.");
    }
    cout << a  << " / " << b << " = " << a / b << endl;

    return 0;
}
