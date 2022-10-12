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

	// output: 0 42 1 42 2 42 3 42 4 42 5 42 6 42 7 42 8 42 9 42
        begin = v.insert(begin, 42);

        ++begin;
    }
    cout << v << endl;

    return 0;
}
