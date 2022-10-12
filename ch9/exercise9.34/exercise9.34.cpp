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
    //vector<int> iv = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> iv = {0, 2, 4, 6, 8};

    auto iter = iv.begin();

    // If iv holds only even values, the while loop will visit all the elements
    // and terminates.
    // If iv holds odd and even values, once iter denotes the first odd value, 
    // the while loop will become inifinite and keep insert the first odd value
    // into the container until the system runs out of memory.
    while (iter != iv.end()) {
        if (*iter % 2)
            iter = iv.insert(iter, *iter);
        ++iter;
    }
    cout << iv << endl;

    return 0;
}
