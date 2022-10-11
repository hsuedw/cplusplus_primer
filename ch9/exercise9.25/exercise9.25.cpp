#include <list>
#include <iostream>

using std::list;
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ostream;

template<typename T> ostream &operator<<(ostream &os, list<T> &c)
{
    auto it = begin(c);
    while (it != end(c)) {
        os << *it << " ";
	++it;
    }
    return os;
}


int main()
{
    list<int> slist = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    auto elem1 = begin(slist), elem2 = begin(slist);
    ++elem1;
    ++elem2;
    // elem1 and elem2 are iterators refer to the same element, and denote an
    // empty iterater range. Therefore, the following statement won't remove any
    // element from slist.
    elem1 = slist.erase(elem1, elem2);
    cout << slist << endl;

    elem1 = end(slist);
    elem2 = end(slist);
    elem1 = slist.erase(elem1, elem2);
    cout << slist << endl;

    return 0;
}
