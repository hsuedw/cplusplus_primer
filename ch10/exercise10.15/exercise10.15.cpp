#include <vector>
#include <iostream>

using std::vector;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

template <typename T> ostream &operator<<(ostream &os, vector<T> vec) 
{
    for (decltype(vec.size()) i = 0; i < vec.size(); ++i) {
        cout << vec[i];
	if (i + 1 != vec.size()) {
            cout << " ";
	}
    }
    return os;
}

int main(int argc, char *argv[])
{
    int a, b;
    cout << "Please input two integers: " << endl;
    cin >> a >> b;

    auto f = [a](const int &y)->int { return a + y; };
    cout << a << " + " << b << " = " << f(b) << endl;

    return 0;
}
