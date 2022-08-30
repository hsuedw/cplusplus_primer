#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int a, b;
    cout << "Please input two integers: " << endl;
    cin >> a >> b;
    if (b == 0) {
        cout << "The divisor must not be zero." << endl;
        return -1;
    }
    cout << a  << " / " << b << " = " << a / b << endl;

    return 0;
}
