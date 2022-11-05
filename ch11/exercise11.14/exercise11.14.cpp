#include <unordered_map>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>

using std::unordered_map;
using std::vector;
using std::pair;
using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

int main(int argc, char *argv[])
{
    unordered_map<string, vector<pair<string, string>>> family_record;
    string first_name, last_name, birthday;

    while (cin >> first_name >> last_name >> birthday) {
        family_record[last_name].push_back(make_pair(first_name, birthday));
    }

    for (const auto &x : family_record) {
        cout << "The " << x.first << "s:" << endl;
	for (const auto &y : x.second) {
            cout << '\t' << y.first << ", " << y.second << endl; // first name, birthday
	}
    }

    return 0;
}
