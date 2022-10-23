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

template <typename T> ostream &operator<<(ostream &os, vector<T> vec) 
{
    for (decltype(vec.size()) i = 0; i < vec.size(); ++i) {
        cout << vec[i];
	if (i + 1 != vec.size()) {
            cout << " ";
	}
    }
    return os;
}

template <typename T> ostream &operator<<(ostream &os, list<T> lst) 
{
    decltype(lst.size()) i = 0;
    for (auto &x : lst) {
        cout << x;
	if (i + 1 != lst.size()) {
            cout << " ";
	}
	++i;
    }
    return os;
}

int main(int argc, char *argv[])
{
    vector<int> vec;
    list<int> lst;
    int i;
    while (cin >> i) {
        lst.push_back(i);
    }

    // Because vec is empty, copy will access invalid memory while values are
    // copied into vec.
    //copy(lst.cbegin(), lst.cend(), vec.begin);

    // I would like to use back_insert to get the third iterator for copy.
    // This way can fix the above issue.
    copy(lst.cbegin(), lst.cend(), back_inserter(vec));
    cout << "lst: " << lst << endl;
    cout << "vec: " << vec << endl;


    return 0;
}
