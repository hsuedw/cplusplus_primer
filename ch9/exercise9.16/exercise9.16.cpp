#include <vector>
#include <list>
#include <iostream>

using std::vector;
using std::list;
using std::ostream;
using std::istream;
using std::cout;
using std::endl;

template <typename T> ostream &operator<<(ostream &os, vector<T> &nums)
{
    for (decltype(nums.size()) i = 0; i < nums.size(); ++i) {
        os << nums[i];
	if (i != nums.size() - 1) {
            os << ", ";
	}
    }
    return os;
}

bool operator==(const vector<int> &vec, const list<int> &lst)
{
    auto vecIt = begin(vec);
    auto lstIt = begin(lst);
    while (vecIt != end(vec) && lstIt != end(lst)) {
        if (*vecIt != *lstIt) {
            return false;
        }
	++vecIt;
	++lstIt;
    }
    return vecIt == end(vec) && lstIt == end(lst);
}

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    list<int> lst1 = {1, 2, 3, 4, 5, 6, 7};
    list<int> lst2 = {1, 2, 3, 4, 5};
    list<int> lst3 = {1, 2, 3, 4, 5, 6, 7, 8};
    list<int> lst4 = {1, 2, 3, 4, 5, 7, 6};


    cout << (vec == lst1) << endl;
    cout << (vec == lst2) << endl;
    cout << (vec == lst3) << endl;
    cout << (vec == lst4) << endl;

    return 0;
}
