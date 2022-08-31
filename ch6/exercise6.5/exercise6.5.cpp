#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int abs(int n)
{
    if (n < 0) {
        return -n;
    }
    return n;
}

int main()
{
    int n;
    cout << "Please enter an integer: ";
    cin >> n;

    cout << "|" << n << "| = "  << abs(n) << endl;
    return 0;
}
