#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main(int argc, char *argv[])
{
    if (argc < 3) {
        return -1;
    }

    string s = argv[1];
    s += argv[2];
    cout << s << endl;

    return 0;
}
