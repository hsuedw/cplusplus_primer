#include <list>
#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>

using std::list;
using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

template <typename T> ostream &operator<<(ostream &os, list<T> lst) 
{
    auto last = end(lst);
    --last;
    for (auto it = begin(lst); it != end(lst); ++it) {
        cout << *it;
	if (it != last) {
            cout << " ";
	}
    }
    return os;
}

void elimDups(list<string> &words)
{
    words.sort();
    words.unique();
}

int main(int argc, char *argv[])
{
    list<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};

    elimDups(words);
    cout << words << endl;

    return 0;
}
