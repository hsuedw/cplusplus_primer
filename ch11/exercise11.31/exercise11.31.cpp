#include <map>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <iostream>
#include <iterator>

using std::multimap;
using std::vector;
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
    cout << authors << endl;

    string author_delete = "Barth, John";
    //string author_delete = "Stanley, Lippman";
    //string author_delete = "Barbara Moo";

    //pair<multimap<string, string>::iterator, multimap<string, string>::iterator> pos = authors.equal_range(author_delete);
    auto pos = authors.equal_range(author_delete);
    if (pos.first != pos.second) {
        authors.erase(pos.first);
    }

    cout << "After delete:" << endl;
    cout << authors << endl;

    return 0;
}
