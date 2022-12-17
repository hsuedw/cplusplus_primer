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
    const char *s1 = "Hello " ;   
    const char *s2 = "World!" ; 
    size_t n = 0;

    // Count the length of the concatenated string.
    for (size_t i = 0; s1[i] != '\0'; ++i) {
        ++n;
    }
    for (size_t i = 0; s2[i] != '\0'; ++i) {
        ++n;
    }
    ++n; // add the space for '\0'

    char *ps = new char[n];
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
