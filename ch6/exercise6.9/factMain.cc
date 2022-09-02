#include <iostream>
#include <Chapter6.h>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int n;
    cout << "Please enter an integer: ";
    cin >> n;

    cout << n << "! = "  << fact(n) << endl;
    return 0;
}
