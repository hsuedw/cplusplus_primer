#include <cstddef>
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    // Identify the indexing errors in the following code:
    constexpr size_t array_size = 10;
    int ia[array_size];

    // The condition part of this for loop is incorrect.
    // Because the valid indices for ia are 0, 1, 2, ..., 9,
    // 'ix <= array_size' makes the body of this for loop 
    // will be run when ix is 10, which is an invalid index.
    //
    // If we want to traverse the whole array and assing 
    // each element a value, the following code can fix
    // this issue.
    //     for (size_t ix = 0; ix < array_size; ++ix)
    for (size_t ix = 1; ix <= array_size; ++ix)
        ia[ix] = ix;

    for (auto &x : ia) 
        cout << x << " ";
    cout << endl;

    return 0;
}
