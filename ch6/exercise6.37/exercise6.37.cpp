#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

string strList[] = { "a", "bb", "ccc", "dddd", "eeeee", "ffffff", "ggggggg", "hhhhhhhh", "iiiiiiiii", "jjjjjjjjjj" };

typedef string arrType[10];
//using arrType = string[10];
arrType &func2()
{
    return strList;
}

auto func3() -> string (&)[10]
{
    return strList;
}

decltype(strList) &func4()
{
    return strList;
}

int main()
{
    arrType &ref2 = func2();
    for (const auto &x : ref2) {
        cout << x << " ";
    }
    cout << endl;

    arrType &ref3 = func3();
    for (const auto &x : ref3) {
        cout << x << " ";
    }
    cout << endl;

    arrType &ref4 = func4();
    for (const auto &x : ref4) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
