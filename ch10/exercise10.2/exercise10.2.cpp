#include <string>
#include <list>
#include <algorithm>
#include <iostream>

using std::string;
using std::list;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

template <typename T> ostream &operator<<(ostream &os, list<T> lst) 
{
    for (decltype(lst.size()) i = 0; i < lst.size(); ++i) {
        cout << lst[i];
	if (i + 1 != lst.size()) {
            cout << " ";
	}
    }
    return os;
}

int main(int argc, char *argv[])
{
    string target;
    cout << "Please input the target string to count: " << endl;
    cin >> target;

    cout << "Please input a sequence of strings: " << endl;
    string x;
    list<string> nums;
    while (cin >> x) {
        nums.push_back(x);
    }

    cout << "The string \"" << target << "\" happens "  << count(begin(nums), end(nums), target) <<  " time(s) in the input sequence." << endl;

    return 0;
}
