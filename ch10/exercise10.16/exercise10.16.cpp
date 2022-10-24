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

// I modified the solution for Exercise 10.9 to meet the requirement for this
// exercise (10.16)

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

string make_plural(size_t ctr, const string &word, 
		                const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}

void biggies(vector<string> &words, string::size_type sz)
{
    elimDups(words); // put words in alphabetical order and remove duplicates

    // sort words by size, but maintain alphabetical order for words of the same
    // size
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b){ return a.size() < b.size(); });

    // get an iterator to the first element whose size() is >= sz
    auto wc = find_if(words.begin(), words.end(), [sz](const string &a) {return a.size() >= sz; });

    // compute the number of elements with size >= sz
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s")
         << " of length " << sz << " or longer" << endl;

    // print words of the given size or longer, each one followed by a space
    for_each(wc, words.end(),
              [](const string &s) { cout << s << " "; } );
    cout << endl;
}

int main(int argc, char *argv[])
{
    vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};

    biggies(words, 5);

    return 0;
}
