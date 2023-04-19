
#include <iostream>

using std::cout;
using std::endl;

class numbered {
public:
    int mysn;
    numbered();
    numbered(const numbered &);
private:
    static int serialNumber;
};

int numbered::serialNumber = 0;

numbered::numbered() {
    mysn = serialNumber++;
}

numbered::numbered(const numbered &rhs) {
    mysn = serialNumber++;
}

void f(numbered s) {
    cout << s.mysn << endl;
}

int main() {
    numbered a, b = a, c = b;
    //The serial numbers for a, b and c are 0, 1 and 2, respectively.
    cout << "a: " << a.mysn << ", b: " << b.mysn << ", c: "  << c.mysn << endl;
 
    f(a); // prints 3
    f(b); // prints 4
    f(c); // prints 5

    return 0;
}
