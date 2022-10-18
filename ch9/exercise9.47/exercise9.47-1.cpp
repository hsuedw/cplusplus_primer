#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;


int main()
{
    string s = "ab2c3d7R4E6";
    string::size_type pos = 0;

    string numSet = "0123456789";
    while ((pos = s.find_first_of(numSet, pos)) != string::npos) {
        cout << "found " << s[pos] << " at index: " << pos << endl;
	++pos;
    }

    pos = 0;
    string alphaSet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    while ((pos = s.find_first_of(alphaSet, pos)) != string::npos) {
        cout << "found " << s[pos] << " at index: " << pos << endl;
	++pos;
    }

    return 0;
}
