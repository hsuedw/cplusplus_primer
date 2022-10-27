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
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> lst_insert, lst_back_insert, lst_front_insert;
    auto lst_insert_iter = inserter(lst_insert, begin(lst_insert));
    auto lst_back_insert_iter = back_inserter(lst_back_insert);
    auto lst_front_insert_iter = front_inserter(lst_front_insert);

    copy(begin(vec), end(vec), lst_insert_iter);
    copy(begin(vec), end(vec), lst_back_insert_iter);
    copy(begin(vec), end(vec), lst_front_insert_iter);

    // prints 1 2 3 4 5 6 7 8 9
    cout << "vec: " << vec << endl;

    // lst_insert is initially empty. By using inerter, the newly added element
    // is inserted ahead of the element denoted by lst_insert_iter. After the
    // insertion, lst_insert_iter referred to the same element before the
    // insertion.
    // Therefore, the following statement prints 1 2 3 4 5 6 7 8 9
    cout << "lst_insert: " << lst_insert << endl;

    // lst_back_insert, is initially empty.
    // By using back_inserter, the newly added element is appended to 
    // lst_back_insert.
    // Therefore, the following statement prints 1 2 3 4 5 6 7 8 9
    cout << "lst_back_insert: " << lst_back_insert << endl;

    // lst_front_insert, is initially empty.
    // By using front_inserter, the newly added element is prepended to 
    // lst_front_insert_iter.
    // Therefore, the following statement prints 9 8 7 6 5 4 3 2 1
    cout << "lst_front_insert: " << lst_front_insert << endl;

    return 0;
}
