#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void printVec(const vector<int> &vec, vector<int>::size_type i)
{
    if (vec.empty() || i >= vec.size()) {
        return;
    }

#ifndef NDEBUG
    cout << "DEBUG: vec.size() = " << vec.size() << ", i = " << i << endl;
#endif

    cout << vec[i];
    if (i + 1 != vec.size()) {
        cout << " ";
    }
    printVec(vec, i + 1);
}

void printVecBackward(const vector<int> &vec, int i)
{
    if (vec.empty() || i >= vec.size()) {
        return;
    }

    printVecBackward(vec, i + 1);

#ifndef NDEBUG
    cout << "DEBUG: vec.size() = " << vec.size() << ", i = " << i << endl;
#endif
    cout << vec[i];
    if (i != 0) {
        cout << " ";
    }
}

int main(int argc, char *argv[])
{
    vector<int> vec1 = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    vector<int> vec2;
    vector<int> vec3 = {22};

    cout << "vec1: {";
    printVec(vec1, 0);
    cout << "}" << endl;

    cout << "vec1: {";
    printVecBackward(vec1, 0);
    cout << "}" << endl;

    cout << "vec2: {";
    printVec(vec2, 0);
    cout << "}" << endl;

    cout << "vec2: {";
    printVecBackward(vec2, 0);
    cout << "}" << endl;

    cout << "vec3: {";
    printVec(vec3, 0);
    cout << "}" << endl;

    cout << "vec3: {";
    printVecBackward(vec3, 0);
    cout << "}" << endl;

    return 0;
}
