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
    double init;
    cout << "Please input an initial value (double) to accumuate: " << endl;
    cin >> init;

    cout << "Please input a sequence of floating point numbers (double): " << endl;
    double x;
    vector<double> nums;
    while (cin >> x) {
        nums.push_back(x);
    }

    // Because the literal 0 is an integer, all the floating point number in
    // nums will be implicitly converted to int, the result is an int.
    cout << "The sum is " << accumulate(nums.begin(), nums.end(), 0) << endl;

    // To fix this issu, the third argument should be given as a double.
    cout << "The sum is " << accumulate(nums.begin(), nums.end(), init) << endl;

    return 0;
}
