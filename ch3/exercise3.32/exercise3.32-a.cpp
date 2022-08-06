#include <iostream>

using std::cout;
using std::endl;

int main()
{
    constexpr size_t sz = 10;
    int array[sz];

    for (size_t i = 0; i < sz; ++i) {
        array[i] = i;
    }

    int array2[sz];
    for (size_t i = 0; i < sz; ++i) {
        array2[i] = array[i];
    }

    cout << "values in array: "; 
    for (auto &x : array) {
        cout << x << " ";
    }
    cout << endl;

    cout << "values in array2: "; 
    for (auto &x : array2) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
