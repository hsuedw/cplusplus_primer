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

// I modified the solution for Exercise 10.19 to meet the requirement for this
// exercise (10.20)

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
    cout << "Please input a positive integer: " << endl;
    int cnt;

    cin >> cnt;
    if (cnt <= 0) {
        cout << "The input integer is not a positive integer." << endl;
	return -1;
    }

    auto f = [&cnt]() -> bool { return cnt--; };

    cout << "cnt 1: " << cnt << endl;
    while (f()) {
        cout << "cnt 2: " << cnt << endl;
    }

    return 0;
}
