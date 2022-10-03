#include <vector>

using std::vector;

int main()
{
#if 0
    vector<int> v1;
    const vector<int> v2;
    auto it1 = v1.begin(), it2 = v2.begin();
    auto it3 = v1.cbegin(), it4 = v2.cbegin();

#else
    vector<int> v1;
    const vector<int> v2;
    auto it1 = v1.begin();
    auto it2 = v2.begin();
    auto it3 = v1.cbegin();
    auto it4 = v2.cbegin();
#endif

    return 0;
}
