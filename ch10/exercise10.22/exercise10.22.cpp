#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <functional>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;
using namespace std::placeholders;

// I modified the solution for Exercise 10.20 to meet the requirement for this
// exercise (10.22)

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
    stable_sort(begin(words), end(words));

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

bool check_size(const string &s, string::size_type sz)
{
    return s.size() >= sz;
}

void biggies(vector<string> &words, string::size_type sz)
{
    elimDups(words); // put words in alphabetical order and remove duplicates

    // sort words by size, but maintain alphabetical order for words of the same
    // size
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b){ return a.size() < b.size(); });

    // get an iterator to the first element whose size() is >= sz
    auto wc = stable_partition(words.begin(), words.end(), [sz](const string &a) { return a.size() < sz; });

    // compute the number of elements with size >= sz
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s")
         << " of length " << sz << " or longer" << endl;

    // print words of the given size or longer, each one followed by a space
    for_each(wc, words.end(),
              [](const string &s) { cout << s << " "; } );
    cout << endl;

    //count = count_if(words.begin(), words.end(), [sz](const string &s){ return s.size() > sz; });
    count = count_if(words.begin(), words.end(), bind(check_size, _1, sz));
    cout << count << " " << make_plural(count, "word", "s") << " logner than " << sz << "." << endl;
}

int main(int argc, char *argv[])
{
    vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};

    biggies(words, 6);

    return 0;
}
