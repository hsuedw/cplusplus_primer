#include <iterator>
#include <iostream>

using std::begin;
using std::end;
using std::cout;
using std::endl;

#define LEN (10)

int main()
{
    int ia[LEN];
    auto pend = end(ia);

    cout << "Before reset: ";
    for (auto pit = begin(ia); pit != pend; ++pit) {
        cout << *pit << " ";
    }
    cout << endl;

    // Reset to 0
    for (auto pit = begin(ia); pit != pend; ++pit) {
        *pit = 0;
    }

    cout << "After reset: ";
    for (auto x : ia) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
