#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main()
{
    string s;
    s.reserve(100);

    char c;
    while (cin.read(&c, 1)) {
        s.push_back(c);
    }
    cout << s << endl;

    return 0;
}
