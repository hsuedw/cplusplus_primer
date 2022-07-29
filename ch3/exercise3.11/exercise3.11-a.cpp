#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main()
{
    const string s = "Keep out!";
    string s2;
    for (auto& c : s) {
        s2.push_back(c);
    }
    cout << s2 << endl;

    return 0;
}
