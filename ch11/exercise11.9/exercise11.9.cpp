#include <map>
#include <set>
#include <list>
#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <cctype>

using std::map;
using std::list;
using std::set;
using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

int main(int argc, char *argv[])
{
    map<string, list<size_t>> word_to_line_num;
    set<string> exclude = {"The", "But", "And", "Or", "An", "A", 
                           "the", "but", "and", "or", "an", "a"};
    string line;
    size_t line_num = 0;

    while (getline(cin, line)) {
        auto left_it = line.begin(), right_it = line.begin();
        while ((right_it = find(left_it, line.end(), ' ')) != line.end()) {
            string word(left_it, right_it);

            if (word.back() == '.' || word.back() == ',') {
                word.pop_back();
            }

	    if (word.size() == 0) {
                goto skip_this_word;
	    }

            // Convert all Englist letters to lower case.
            for (auto &c: word) {
                if (isalpha(c)) {
                    c |= 0x20;
                }
            }

            if (exclude.count(word) != 0) {
                goto skip_this_word;
            }

            word_to_line_num[word].push_back(line_num);

skip_this_word:
            ++right_it;
            left_it = right_it;
        }
	++line_num;
    }

    for (const auto &x : word_to_line_num) {
        cout << x.first << ": ";
	for (const auto &y : x.second) {
            cout << y << " ";
	}
	cout << endl;
    }

    return 0;
}
