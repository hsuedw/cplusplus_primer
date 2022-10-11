#include <forward_list>
#include <string>
#include <iostream>

using std::forward_list;
using std::string;
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ostream;

template<typename T> ostream &operator<<(ostream &os, forward_list<T> &c)
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
    //forward_list<string> sflst = { "aa", "bb", "cc", "dd", "ee", "ff", "gg" };
    //forward_list<string> sflst = { "aa" };
    forward_list<string> sflst;
    cout << "sflst: " << sflst << endl;

    string target = "aa";
    //string target = "gg";
    //string target = "xx";
    string newstr = "hello world";

    auto prev = sflst.before_begin();
    auto curr = begin(sflst);
    while (!sflst.empty() && curr != end(sflst)) {
        if (*curr == target) {
            sflst.insert_after(curr, newstr);
	    break;
        }
	prev = curr;
        ++curr;
    }
    if (curr == end(sflst)) {
        sflst.insert_after(prev, newstr);
    }
    cout << "sflst: " << sflst << endl;

    return 0;
}
