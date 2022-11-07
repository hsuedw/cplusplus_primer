#include <map>
#include <string>
#include <iostream>

using std::map;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    map<string, size_t> word_count;
    string word;
    while (cin >> word) {
        if (word_count.find(word) != word_count.end()) {
            ++word_count[word];
	} else {
            // word doesn't exist in word_count.
            word_count.insert({word, 1});
	}
    }

    for (const auto &w : word_count) {
        cout << w.first << " occurs " << w.second
             << ((w.second > 1) ? " times" : " time") << endl;
    }

    return 0;
}
