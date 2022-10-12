#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;
using std::ostream;

template<typename T> ostream &operator<<(ostream &os, vector<T> &c)
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
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto begin = v.begin();

    while (begin != v.end()) {
        ++begin;

	// Because insert will place the newly added element immediately before
	// the element denoted by begin, the iterator, begin, will become
	// invalidated. 
        v.insert(begin, 42);

	// Then, the behavior of this statement is undefined. This can lead to a
	// runtime error.
        ++begin;
    }
    cout << v << endl;

    return 0;
}
