#include <iostream>
using namespace std;

int main() {
    int i = 42;      // Initialize the int variable i to be 42.
    std::cout << "Address of i: " << &i << std::endl;

    int *p1 = &i;    // Initialize pi to be the address of i.
    std::cout << "Value of p1: " << p1 << std::endl;

    *p1 = *p1 * *p1; // Assign the object to which p1 points to be 42 * 42
    std::cout << "*p: " << *p1 << std::endl;

    return 0;
}
