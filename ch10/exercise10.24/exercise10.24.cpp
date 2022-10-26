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

bool check_size(const string &s, string::size_type sz)
{
    return s.size() < sz;
}

void biggies(vector<int> &nums, const string &s)
{
    auto it = find_if(begin(nums), end(nums), bind(check_size, s, _1));

    if (it == end(nums)) {
        cout << "In nums, there is no element whose value is greater than " << s.size() << "." << endl;
    } else {
        vector<int>::size_type p = it - begin(nums);
        cout << "In nums, the first element whose value is greater than " << s.size() << " is " << p << "." << endl;
    }
}

int main(int argc, char *argv[])
{
    vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

    cout << "Please input a string: " << endl;
    string s;
    cin >> s;

    biggies(nums, s);

    return 0;
}
