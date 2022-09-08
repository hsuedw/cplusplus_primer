#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

inline bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

int main()
{
    string s1 = "hello";
    //string s2 = "world";
    string s2 = "Edward";
    if (isShorter(s1, s2)) {
        cout << s1 << " is shorter than "  << s2 << "." << endl;
    } else {
        cout << s1 << " is not shorter than "  << s2 << "." << endl;
    }

    return 0;
}
