#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void print_vec(vector<int> &vec)
{
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    print_vec(vec);

    for (auto it = vec.begin(); it != vec.end(); ++it) {
        *it = *it * 2;
    }

    print_vec(vec);

    return 0;
}
