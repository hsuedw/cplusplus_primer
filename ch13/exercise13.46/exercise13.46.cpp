#include <iostream>
#include <vector>

using namespace std;

int f() {
    return 123;
}

vector<int> vi(100);

int main() {
    int&& r1 = f();
    int& r2 = vi[0];
    int& r3 = r1;
    int&& r4 = vi[0] * f();

    cout << r1 << endl;
    cout << r2 << endl;
    cout << r3 << endl;
    cout << r4 << endl;

    return 0;
}
