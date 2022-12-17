#include <string>
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

int main(int argc, char *argv[])
{
    string s1("Hello ");   
    string s2("World!"); 

    char *ps = new char[s1.size() + s2.size() + 1];
    size_t j = 0;
    for (size_t i = 0; s1[i] != '\0'; ++i) {
        ps[j] = s1[i];
	++j;
    }
    for (size_t i = 0; s2[i] != '\0'; ++i) {
        ps[j] = s2[i];
	++j;
    }
    ps[j] = '\0';

    cout << ps << endl;

    delete [] ps;

    return 0;
}
