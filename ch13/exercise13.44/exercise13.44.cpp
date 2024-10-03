#include <iostream>

#include "String.h"

using namespace std;

int main() {
    String orig1("Hello Edward!!");
    String orig2 = orig1;
    String orig3 = "Hello Angus~~";

    cout << "orig1: " << orig1 << endl;
    cout << "orig2: " << orig2 << endl;
    cout << "orig3: " << orig3 << endl;

    orig1.push_back('A');
    orig1.push_back('B');
    orig2.push_back('C');
    orig2.push_back('D');
    orig3.push_back('E');
    orig3.push_back('F');

    cout << "orig1: " << orig1 << endl;
    cout << "orig2: " << orig2 << endl;
    cout << "orig3: " << orig3 << endl;

    return 0;
}
