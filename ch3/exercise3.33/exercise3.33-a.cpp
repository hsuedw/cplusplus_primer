#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    unsigned scores[11]; // locally define scores but don't initialize its elements to 0
    unsigned grade;
    while (cin >> grade) {
        if (grade <= 100) {
            ++scores[grade / 10];
        }
    }

    for (auto &x : scores) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
