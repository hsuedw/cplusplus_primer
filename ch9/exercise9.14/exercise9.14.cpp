#include <vector>
#include <list>
#include <string>
#include <iostream>

using std::vector;
using std::list;
using std::string;
using std::ostream;
using std::cout;
using std::endl;

template <typename T> ostream &operator<<(ostream &os, vector<T> &nums)
{
    for (decltype(nums.size()) i = 0; i < nums.size(); ++i) {
        os << nums[i];
	if (i != nums.size() - 1) {
            os << ", ";
	}
    }
    return os;
}

int main()
{
    list<const char *> org1 = {"hello", "world", "how", "are", "you", "doing", "how", "may", "I", "help", "you"};
    
    vector<string> copy1;
    copy1.assign(begin(org1), end(org1));
    cout << copy1 << endl;


    return 0;
}
