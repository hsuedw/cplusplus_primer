#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
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
    vector<char> cvec = { 'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '!' };
    string s1(begin(cvec), end(cvec));
    string s2(&cvec[0], cvec.size());

    cout << "cvec: " << cvec << endl;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;

    return 0;
}
