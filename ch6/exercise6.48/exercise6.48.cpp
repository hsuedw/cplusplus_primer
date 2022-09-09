#include <string>
#include <iostream>
#include <cassert>

using std::string;
using std::cin;

int main()
{
    string s, sought = "end";
    while (cin >> s && s != sought) {}
    assert(cin);

    return 0;
}
