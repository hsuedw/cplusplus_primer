#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int main()
{
    vector<int> vec1 {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> vec2 {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> vec3 {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    vector<int> vec4 {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "vec1 and vec2 are ";
    if (vec1 == vec2) {
        cout << "equal." << endl;
    } else {
        cout << "not equal." << endl;
    }

    cout << "vec1 and vec3 are ";
    if (vec1 == vec3) {
        cout << "equal." << endl;
    } else {
        cout << "not equal." << endl;
    }

    cout << "vec1 and vec4 are ";
    if (vec1 == vec4) {
        cout << "equal." << endl;
    } else {
        cout << "not equal." << endl;
    }

    return 0;
}
