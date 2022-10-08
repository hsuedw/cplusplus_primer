#include <string>
#include <list>      // modify 1
#include <iostream>

using std::string;
using std::list;     // modify 2
using std::cout;
using std::cin;
using std::endl;

int main()
{
    string s;
    list<string> dq;   // modify 3
    while (cin >> s) {
       dq.emplace_back(s);
    }

    for (auto it = begin(dq); it != end(dq); ++it) {
        cout << *it << endl;
    }

    return 0;
}
