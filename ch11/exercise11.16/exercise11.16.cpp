#include <map>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>

using std::map;
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
    map<string, int> dict;
    string word;
    int num;

    while (cin >> word >> num) {
        dict[word] = num;
    }

    for (auto it = dict.begin(); it != dict.end(); ++it) {
        it->second *= 2;
        cout <<  it->first << ": " << it->second << endl;
    }

    return 0;
}
