#include <iostream>

using std::cin;
using std::cout;
using std::endl;

bool is_even(int value)
{
    return value % 2 == 0;
}

int main()
{
    cout << "Please enter a value: ";

    int value;
    cin >> value;
    if (is_even(value)) {
        cout << value << " is even." << endl;
    } else {
        cout << value << " is odd." << endl;
    }

    return 0;
}
