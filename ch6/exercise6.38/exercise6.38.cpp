#include <iostream>

using std::cout;
using std::endl;

int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};

decltype(odd) &arrRef(int i)
{
    return (i % 2) ? odd : even;
}

int main()
{
    decltype(odd) &ref1 = arrRef(8);
    for (const auto &x: ref1) {
        cout << x << " ";
    }
    cout << endl;

    decltype(odd) &ref2 = arrRef(5);
    for (const auto &x: ref2) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
