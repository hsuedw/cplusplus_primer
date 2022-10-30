
#include <vector>
#include <list>
#include <iostream>
#include <iterator>
#include <algorithm>

using std::vector;
using std::list;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

template<typename T> ostream &operator<<(ostream &os, vector<T> &vec)
{
    for (decltype(vec.size()) i = 0; i < vec.size(); ++i) {
        os << vec[i];
	if (i + 1 != vec.size()) {
            os << " ";
	}
    }

    return os;
}

template<typename T> ostream &operator<<(ostream &os, list<T> &lst)
{
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        os << *it  << " ";
    }

    return os;
}

int main(int argc, char *argv[])
{
    vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> lst;

    auto vecRit1 = vec.rbegin() + 2;
    auto vecRit2 = vec.rbegin() + 7;
    auto lstBackIt = back_inserter(lst);
    copy(vecRit1, vecRit2, lstBackIt);

    cout << "vec: " << vec << endl;
    cout << "lst: " << lst << endl;

    return 0;
}
