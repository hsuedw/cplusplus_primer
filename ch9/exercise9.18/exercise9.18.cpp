#include <string>
#include <deque>
#include <iostream>

using std::string;
using std::deque;
using std::ostream;
using std::istream;
using std::cout;
using std::cin;
using std::endl;

int main()
{
    string s;
    deque<string> dq;
    while (cin >> s) {
       dq.emplace_back(s);
    }

    for (auto it = begin(dq); it != end(dq); ++it) {
        cout << *it << endl;
    }

    return 0;
}
