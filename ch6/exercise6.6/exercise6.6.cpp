#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int multiply(int v1, int v2)
{
    int product = v1 * v2;
    static unsigned int cnt = 0;
    cout << "multiply() has been called " << ++cnt << " time(s)." << endl;

    return product;
}

int main()
{
    int v1, v2;
    cout << "Please enter two integer: ";

    while (cin >> v1 >> v2) {
        int p = multiply(v1, v2);
        cout << v1 << " * " << v2 << " = " << p << endl;
    }

    return 0;
}
