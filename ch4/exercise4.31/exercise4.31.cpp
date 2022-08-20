#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void print_vec(const vector<int> &ivec) {
    for (const auto &x : ivec) {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    constexpr int sz = 10;
    vector<int> ivec(sz);
    vector<int>::size_type cnt = ivec.size();

    // In this case, the prefix increment/decrement operators have the
    // same effect of the postfix increment/decrement operators.

    for (vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt)
        ivec[ix] = cnt;
    print_vec(ivec);

    cnt = ivec.size();
    for (vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--)
        ivec[ix] = cnt;
    print_vec(ivec);

    return 0;
}
