#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int value;
    while (cin >> value && value != 42) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
