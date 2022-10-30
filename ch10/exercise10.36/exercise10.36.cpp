
#include <list>
#include <iostream>
#include <iterator>
#include <algorithm>

using std::list;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char *argv[])
{
    list<int> lst = {0, 1, 2, 3, 4, 0, 6, 7, 8, 9};
    auto last_zero = find(lst.rbegin(), lst.rend(), 0);

    if (last_zero == lst.rend()) {
        cout << "No zero is found!" << endl;
    } else {
	++last_zero;
        int i = 0;
	for (auto it = lst.begin(); it != last_zero.base(); ++it) {
            ++i;
	}
	cout << "The last zero is at index " << i << "." << endl;
    }

    return 0;
}
