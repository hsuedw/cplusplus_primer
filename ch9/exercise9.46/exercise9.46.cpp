#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;

string &modifyName(string &s, const string &prefix, const string &suffix)
{
    s.insert(0, prefix +" ");
    s.insert(s.size(), " " + suffix, 0, suffix.size() + 1);

    return s;
}

int main()
{
    string name1 = "James";
    name1 = modifyName(name1, "Mr.", "II");
    cout << name1 << endl;

    string name2 = "Woo";
    cout << modifyName(name2, "Miss", "Jr.") << endl;

    return 0;
}
