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
        // Case 1: word does not exist in word_count
        //         A pair will be inserted into word_count. 
        //         The string is the value of word and the size_t is initialized
        //         as 0.
        //         The insert member returns a pair of pair<iterator, bool>. The
        //         iterator refers to the inserted element and the bool will be
        //         true, which indicates an element is inserted successfully.

        // Case 2: word exists in word_count
        //         The insert member returns a pair of pair<iterator, bool>. The
        //         iterator refers to the existing word and bool will be false,
        //         which indicates no element is inserted.

        // In This statement, the insert member returns a pair of pair<iterator,
	// bool>. The iterator refers to the element with key is word. The we
	// use this iterator to access the counter (size_t) which is associated
	// with word. Then, increment the counter.
        ++word_count.insert({word, 0}).first->second;
    }

    for (const auto &w : word_count) {
        cout << w.first << " occurs " << w.second
             << ((w.second > 1) ? " times" : " time") << endl;
    }

#if 0
    word_count.insert({"xxx", 123});
    auto it = word_count.find("xxx");
    cout << ">>> " << it->first << ", " << it->second << endl;

    auto p = word_count.insert({"xxx", 456});
    if (!p.second) {
        cout << "word exists, insert fail!" << endl;
    }
    it = word_count.find("xxx");
    cout << ">>> " << it->first << ", " << it->second << endl;
#endif

    return 0;
}
