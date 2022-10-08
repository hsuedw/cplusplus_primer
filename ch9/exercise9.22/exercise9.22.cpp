#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::cin;
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
    vector<int> iv = {2, 2, 2, 2, 2};
    decltype(iv.size()) idx = 0, mid = iv.size() / 2;
    int some_val = 2;
    while (idx != mid) {
        if (iv[idx] == some_val) {
            iv.insert(begin(iv) + idx, 2 * some_val);
        }
	++idx;
    }

    cout << iv << endl;

    return 0;
}
