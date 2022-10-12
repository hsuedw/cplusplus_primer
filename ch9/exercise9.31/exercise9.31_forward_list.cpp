#include <forward_list>
#include <iostream>

using std::forward_list;
using std::cout;
using std::endl;
using std::ostream;

template<typename T> ostream &operator<<(ostream &os, forward_list<T> &c)
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
    forward_list<int> iflst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto prev = iflst.before_begin();
    auto curr = begin(iflst);

    while (curr != end(iflst)) {
        if (*curr & 0x01) {
            // Because insert places the newly added element before the element
	    // denoted by iter and forward_list is a container for singly linked
	    // list, it can be poor performance to get the predecessor.
	    // Therefore, the operations to add or remove elements in a
	    // forward_list operate by changing the element after the given
	    // element.
            curr = iflst.insert_after(curr, *curr);
	    prev = curr;
            ++curr;
	} else {
            curr = iflst.erase_after(prev);
	}
    }
    cout << iflst << endl;

    return 0;
}
