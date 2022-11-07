#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>

using std::multimap;
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

int main(int argc, char *argv[])
{
    multimap<string, string> family_record;
    string first_name, last_name;

    while (cin >> first_name >> last_name) {
        family_record.insert({last_name, first_name});
    }

    for (const auto &x : family_record) {
        cout << x.first << ", " << x.second << endl;
    }

    return 0;
}
