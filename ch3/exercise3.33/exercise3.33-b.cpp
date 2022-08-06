#include <iostream>

using std::cin;
using std::cout;
using std::endl;

unsigned scores[11]; // Globally define scores. Compiler initializes all its elements to 0.
int main()
{
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
