// This code is modified from Exercise 7.27.
// It is buggy to verify whether the idea in Exercise 7.28 is correct.

#include <iostream>
#include "Screen.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main()
{
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(cout);
    cout << "\n";
    myScreen.display(cout);
    cout << "\n";

    return 0;
}
