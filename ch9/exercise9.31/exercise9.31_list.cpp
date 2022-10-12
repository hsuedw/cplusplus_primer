#include <list>
#include <iostream>

using std::list;
using std::cout;
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
    list<int> ilst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto curr = begin(ilst);

    while (curr != end(ilst)) {
        if (*curr & 0x01) {
            curr = ilst.insert(curr, *curr);
            // Now, curr denotes to the newly added node which is placed
	    // immediately before the node that was orginally denoted by curr.

            // Because list is a doubly linked list container, it doesn't
	    // support random access. We have to use sequential access.
            ++curr;
	    ++curr;
	} else {
            curr = ilst.erase(curr);
	}
    }
    cout << ilst << endl;

    return 0;
}
