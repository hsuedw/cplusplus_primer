#include <list>
#include <deque>
#include <iostream>

using std::list;
using std::deque;
using std::cout;
using std::cin;
using std::endl;
using std::ostream;

ostream &operator<<(ostream &os, deque<int> &c)
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
    int num;
    list<int> lst;
    while (cin >> num) {
       lst.emplace_back(num);
    }

    deque<int> odd, even;
    for (auto it = begin(lst); it != end(lst); ++it) {
        if (*it & 0x01) {
            // odd number
            odd.emplace_back(*it);
        } else {
            // even number
            even.emplace_back(*it);
	}
    }

    cout << "odd: " << odd << endl;
    cout << "even: "  << even << endl;

    return 0;
}
