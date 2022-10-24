#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

template <typename T> ostream &operator<<(ostream &os, vector<T> vec) 
{
    for (decltype(vec.size()) i = 0; i < vec.size(); ++i) {
        cout << vec[i];
	if (i + 1 != vec.size()) {
            cout << " ";
	}
    }
    return os;
}

void elimDups(vector<string> &words)
{
    sort(begin(words), end(words));

    vector<int>::size_type i = 0, j = 1;
    while (j < words.size()) {
        if (words[i] != words[j]) {
            ++i;
	    swap(words[i], words[j]);
	    ++j;
	} else {
            // words[i] == words[j] is true
            ++j;
        }
    }

    // words[i] is the last unique word.
    // All the words beyond the index i are duplicated words.

    // Use the pop_back member function to delete all the duplicated words.
    while (words.size() > i + 1) {
        words.pop_back();
    }

}

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

int main(int argc, char *argv[])
{
    vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};

    elimDups(words);
    stable_sort(begin(words), end(words), isShorter);
    cout << words << endl;

    return 0;
}
