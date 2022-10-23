#include <vector>
#include <numeric>
#include <iostream>

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
    int init;
    cout << "Please input an initial value to accumuate: " << endl;
    cin >> init;

    cout << "Please input a sequence of integers: " << endl;
    int x;
    vector<int> nums;
    while (cin >> x) {
        nums.push_back(x);
    }

    cout << "The sum is " << accumulate(nums.begin(), nums.end(), init) << endl;

    return 0;
}
