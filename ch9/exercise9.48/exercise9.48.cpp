#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;


int main()
{
    string numbers("0123456789"), name("r2d2");
    string::size_type pos = numbers.find(name);

    if (pos != string::npos) {
        cout << "pos: " << pos << endl;
    } else {
        cout << "pos is npos." << endl;
    }

    return 0;
}
