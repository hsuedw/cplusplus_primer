#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

bool isPrefix(vector<int> &v1, vector<int> &v2)
{
    decltype(v1.size()) i;
    for (i = 0; i < v1.size() && i < v2.size(); ++i) {
        if (v1[i] != v2[i]) {
            break;
        }   
    }

    return i >= v1.size() || i >= v2.size();
}

int main()
{
    vector<int> vec1 = {0, 1, 2};
    vector<int> vec2 = {0, 1, 2, 3, 4, 5, 6};
    vector<int> vec3 = {0, 2, 1};
    vector<int> vec4 = {0, 1, 2, 3, 4, 5, 6, 7};

    if (isPrefix(vec1, vec2)) {
        cout << "vec1 is the prefix of vec2." << endl;
    } else {
        cout << "vec1 is not the prefix of vec2." << endl;
    }

    if (isPrefix(vec3, vec4)) {
        cout << "vec3 is the prefix of vec4." << endl;
    } else {
        cout << "vec3 is not the prefix of vec4." << endl;
    }

    return 0;
}
