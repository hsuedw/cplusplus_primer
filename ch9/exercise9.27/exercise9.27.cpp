#include <forward_list>
#include <iostream>

using std::forward_list;
using std::cout;
using std::cerr;
using std::cin;
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
    forward_list<int> iflst = { 13, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    cout << "iflst: " << iflst << endl;

    auto curr = begin(iflst);
    auto prev = iflst.before_begin();
    while (!iflst.empty() && curr != end(iflst)) {
        if (*curr & 0x01) {
            curr = iflst.erase_after(prev);
	} else {
            prev = curr;
	    ++curr;
	}
    }
    cout << "iflst (erased): " << iflst << endl;

    return 0;
}
