
#include <iostream>

using std::cout;
using std::endl;

class numbered {
public:
    int mysn;
    numbered();
private:
    static int serialNumber;
};

int numbered::serialNumber = 0;

numbered::numbered() {
    mysn = serialNumber++;
}

void f(numbered s) {
    cout << s.mysn << endl;
}

int main() {
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);

    return 0;
}
