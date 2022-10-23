#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

using std::vector;
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

int main(int argc, char *argv[])
{
    vector<int> vec;

    fill_n(back_inserter(vec), 10, 0);
    cout << vec << endl;

    return 0;
}
