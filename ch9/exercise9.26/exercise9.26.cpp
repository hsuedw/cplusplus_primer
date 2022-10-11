#include <list>
#include <vector>
#include <iostream>

using std::list;
using std::vector;
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
    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
    size_t sz= sizeof(ia) / sizeof(ia[0]);

    vector<int> ivec(ia, ia + sz);
    list<int> ilst(ia, ia + sz);
    cout << "ivec: " << ivec << endl;
    cout << "ilist: " << ilst << endl;

    auto itVec = begin(ivec);
    while (!ivec.empty() && itVec != end(ivec)) {
        if (*itVec & 0x01) {
            ++itVec;
	} else {
            itVec = ivec.erase(itVec);
	}
    }
    cout << "ivec (erased): " << ivec << endl;

    auto itLst = begin(ilst);
    while (!ilst.empty() && itLst != end(ilst)) {
        if (*itLst & 0x01) {
            itLst = ilst.erase(itLst);
	} else {
            ++itLst;
	}
    }
    cout << "ilist (erased): " << ilst << endl;

    return 0;
}
