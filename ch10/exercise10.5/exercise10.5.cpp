#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;
using std::equal;

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

int main(int argc, char *argv[])
{
    char const *roster1[] = {"John", "Marry", "Angus", "Edward"};
    char const *roster2[] = {"John", "Marry", "Angus", "Edward"};

    cout << equal(roster1, roster1 + 4, roster2) << endl;

    return 0;
}
