#include <iostream>
#include <initializer_list>

using std::cout;
using std::endl;
using std::initializer_list;

int mySum(initializer_list<int> nums)
{
    int sum = 0;
    for (const auto x : nums) {
        sum += x;
    }
    return sum;
}

int main(int argc, char *argv[])
{
    cout << mySum({11, 22, 33, 44, 55, 66, 77, 88, 99}) << endl;

    return 0;
}
