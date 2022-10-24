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

    auto f = [](const int &x, const int &y)->int { return x + y; };
    cout << a << " + " << b << " = " << f(a, b) << endl;
    
    auto g = [a, b]() { return a + b; };
    cout << a << " + " << b << " = " << g() << endl;

    return 0;
}
