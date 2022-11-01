#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <cctype>

using std::unordered_map;
using std::unordered_set;
using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

int main(int argc, char *argv[])
{
    unordered_map<string, size_t> word_count;
    unordered_set<string> exclude = {"The", "But", "And", "Or", "An", "A", 
                                     "the", "but", "and", "or", "an", "a"};
    string word;

    while (cin >> word) {
        if (word.back() == '.' || word.back() == ',') {
            word.pop_back();
        }

	// Convert all Englist letters to lower case.
	for (auto &c: word) {
            if (isalpha(c)) {
                c |= 0x20;
            }
	}

        if (exclude.count(word) == 0) {
            ++word_count[word];
        }
    }

    for (const auto &x : word_count) {
        cout << x.first << " occurs " << x.second 
             << ((x.second > 1) ? " times" : " time") << endl;
    }

    return 0;
}
