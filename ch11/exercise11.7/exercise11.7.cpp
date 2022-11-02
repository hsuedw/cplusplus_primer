#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>

using std::unordered_map;
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

int main(int argc, char *argv[])
{
    unordered_map<string, vector<string>> family_record;
    string first_name, last_name;

    while (cin >> first_name >> last_name) {
        family_record[last_name].push_back(first_name);
    }

    for (const auto &x : family_record) {
        cout << "The " << x.first << "s:" << endl;
	for (const auto &y : x.second) {
            cout << '\t' << y << endl;
	}
    }

    return 0;
}
