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
