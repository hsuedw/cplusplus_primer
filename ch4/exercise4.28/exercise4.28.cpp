#include <iostream>

using std::cout;
using std::endl;
using std::hex;

int main()
{
    cout << "The size of bool: " << sizeof(bool) << endl;
    cout << "The size of char: " << sizeof(char) << endl;
    cout << "The size of wchar_t: " << sizeof(wchar_t) << endl;
    cout << "The size of char16_t: " << sizeof(char16_t) << endl;
    cout << "The size of char32_t: " << sizeof(char32_t) << endl;
    cout << "The size of short: " << sizeof(short) << endl;
    cout << "The size of int: " << sizeof(int) << endl;
    cout << "The size of long: " << sizeof(long) << endl;
    cout << "The size of long long: " << sizeof(long long) << endl;
    cout << "The size of double: " << sizeof(double) << endl;
    cout << "The size of float: " << sizeof(float) << endl;
    cout << "The size of long double: " << sizeof(long double) << endl;

    return 0;
}
