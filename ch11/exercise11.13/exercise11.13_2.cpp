#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>

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
    vector<pair<string, int>> data;
    string word;
    int num;
    while (cin >> word >> num) {
        data.push_back({word, num});
    }

    for (const auto &p : data) {
        cout << p.first << ": " << p.second << endl;
    }

    return 0;
}
