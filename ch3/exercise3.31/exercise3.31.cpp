#include <iostream>
using namespace std;

using std::cout;
using std::endl;

int main()
{
    constexpr size_t sz = 10;
    int array[sz];

    for (size_t i = 0; i < sz; ++i) {
        array[i] = i;
    }

    for (auto &x : array) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
