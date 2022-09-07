#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

string strList[] = { "a", "bb", "ccc", "dddd", "eeeee", "ffffff", "ggggggg", "hhhhhhhh", "iiiiiiiii", "jjjjjjjjjj" };

string (&func1()) [10]
{
    return strList;
}

int main()
{
    string (&ref1)[10] = func1();
    for (const auto &x : ref1) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
