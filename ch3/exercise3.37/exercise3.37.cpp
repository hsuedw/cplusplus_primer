#include <iostream>

using std::cout;
using std::endl;

int main()
{
    const char ca[] = {'h', 'e', 'l', 'l', 'o'};  // ERROR! Not null terminated
    //const char ca[] = {'h', 'e', 'l', 'l', 'o', '\0'}; // fix the issue by appending a null character.
    const char *cp = ca;
    while (*cp) {
        cout << *cp << endl;
	++cp;
    }
    return 0;
}
