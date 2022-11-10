#include <map>
#include <string>
#include <utility>
#include <algorithm>
#include <iostream>
#include <iterator>

using std::multimap;
using std::string;
using std::pair;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

ostream &operator<<(ostream &os, multimap<string, string>& m)
{
    for (const auto &x : m) {
        cout << x.first << ", " << x.second << endl;
    }

    return os;
}

int main(int argc, char *argv[])
{
    multimap<string, string> authors;
    string author, book_title;

    authors.insert({"Barth, John", "Sot-weed Factor"});
    authors.insert({"Barth, John", "Lost in the Funhouse"});
    authors.insert({"Stanley, Lippman", "C++ primer"});
    authors.insert({"Rosen", "Discret Mathematics and Its Applications"});
    authors.insert({"Bjarne Stroustrup", "A Tour of C++"});
    authors.insert({"Zed Shaw", "Learn C the Hard Way"});
    authors.insert({"Bjarne Stroustrup", "The C++ Programming Language"});
    authors.insert({"Brian Kernighan and Dennis Richie", "The C Programming Language"});

    cout << authors << endl;

    return 0;
}
