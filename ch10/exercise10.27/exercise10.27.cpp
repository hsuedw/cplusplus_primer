#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <iterator>

using std::vector;
using std::list;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) 
{
    for (decltype(vec.size()) i = 0; i < vec.size(); ++i) {
        cout << vec[i];
	if (i + 1 != vec.size()) {
            cout << " ";
	}
    }
    return os;
}

template <typename T> ostream &operator<<(ostream &os, const list<T> &lst) 
{
    decltype(lst.size()) i = 0, sz = lst.size();
    for (auto it = begin(lst); it != end(lst); ++it) {
        cout << *it;
	if (i + 1 != sz) {
            cout << " ";
	}
	++i;
    }
    return os;
}

int main(int argc, char *argv[])
{
    vector<int> vec = {1, 2, 2, 3, 3, 9, 7, 7, 5, 5, 3, 4, 4, 8};
    list<int> lst;
    auto lst_iter = back_inserter(lst);

    unique_copy(begin(vec), end(vec), lst_iter);

    cout << "vec: " << vec << endl;
    cout << "lst: " << lst << endl;

    return 0;
}
