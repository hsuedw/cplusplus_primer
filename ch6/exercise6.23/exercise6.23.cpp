#include <iostream>
#include <iterator>

using std::cout;
using std::endl;
using std::begin;
using std::end;

void print1(const int * const p)
{
    cout << *p << endl;
}

void print2(const int * const pa, const size_t sz)
{
    for (size_t i = 0; i < sz; ++i) {
        cout << *(pa + i) << " ";
    }
    cout << endl;
}

void print3(const int * const pbeg, const int * const pend)
{
    for (const int *it = pbeg; it != pend; ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    int i = 0, j[2] = {1, 2};

    print1(&i);
    print1(j);
    print2(&i, 1);
    print2(j, end(j) - begin(j));
    print3(begin(j), end(j));

    return 0;
}
