#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
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


/*
 * Before the while loop, we initial iter to begin(vec). The first call to
 * insert takes the string we just read and puts it in front of the element
 * denoted by iter. The value returned by insert is an iterator referring to
 * this new element. We assign that iterator to iter and repeat the while,
 * reading another word. As long as there are words to insert, ech iteration
 * inserts a new element ahead of iter and reassigns to iter and location of the
 * newly inserted element. That element is the (new) first element. Thus, each
 * iteration inserts an element ahead of the first element in the vector.
 */

int main()
{
    string word;
    vector<string> vec;
    auto iter = begin(vec);
    while (cin >> word) {
       iter = vec.insert(iter, word);
    }

    cout << vec << endl;

    return 0;
}
