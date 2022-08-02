#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

template <typename T> void print_vec(vector<T>& vec, const string& name) {
    cout << "the size of " << name << ": " << vec.size() << endl;
    if (vec.begin() != vec.end()) {
        cout << "the contents of " << name << ": ";
        for (auto it = vec.begin(); it != vec.end(); ++it) {
	    cout << "[" << *it << "] ";
	}
        cout << endl;
    }
    cout << endl;
}

int main()
{
    vector<int> v1;
    print_vec(v1, "v1");

    vector<int> v2(10);
    print_vec(v2, "v2");

    vector<int> v3(10, 42);
    print_vec(v3, "v3");

    vector<int> v4{10};
    print_vec(v4, "v4");

    vector<int> v5{10, 42};
    print_vec(v5, "v5");

    vector<string> v6{10};
    print_vec(v6, "v6");

    vector<string> v7{10, "hi"};
    print_vec(v7, "v7");

    return 0;
}
