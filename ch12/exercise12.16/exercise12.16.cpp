#include <string>
#include <iostream>
#include <memory>

using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;
using std::unique_ptr;

int main(int argc, char *argv[])
{
    unique_ptr<string> p1(new string("hello world"));
    unique_ptr<string> p2 = p1; // error: no assign for unique_ptr
    unique_ptr<string> p3(p1); // error: no copy for unique_ptr

    return 0;
}
