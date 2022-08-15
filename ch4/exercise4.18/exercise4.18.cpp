#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    auto pbeg = v.begin();
    while (pbeg != v.end() && *pbeg >= 0)
        cout << *++pbeg << endl;

    return 0;
}
