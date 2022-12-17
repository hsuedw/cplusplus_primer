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
    string line;
    getline(cin, line);

    const size_t max_size = 16;
    char *ps = new char[max_size];
    size_t i = 0;
    while (i + 1 < max_size) {
        ps[i] = line[i];
	++i;
    }
    ps[i] = '\0';

    cout << ps << endl; 
   
    delete [] ps;

    return 0;
}
