#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

// sa is an array of ten empty string objects.
string sa[10];

// ia is an array of ten ints. These int elements in ia are 0,
// because ia is defined globally.
int ia[10];

int main()
{
    // sa2 is an array of ten empty string objects.
    string sa2[10];

    // ia2 is an array of ten ints. These int elements have random values,
    // because ia is defined locally in main().
    int    ia2[10];

    cout << "sa: ";
    for (int i = 0; i < 10; ++i) {
        cout << "\"" << sa[i] << "\" ";
    }
    cout << endl;

    cout << "ia: ";
    for (int i = 0; i < 10; ++i) {
        cout << ia[i] << " ";
    }
    cout << endl;

    cout << "sa2: ";
    for (int i = 0; i < 10; ++i) {
        cout << "\"" << sa2[i] << "\" ";
    }
    cout << endl;

    cout << "ia2: ";
    for (int i = 0; i < 10; ++i) {
        cout << ia2[i] << " ";
    }
    cout << endl;

    return 0;
}
