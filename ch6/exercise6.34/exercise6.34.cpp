#include <iostream>

using std::cout;
using std::endl;

int factorial(int val)
{
    if (val != 0)
        return factorial(val - 1) * val;
     return 1;
}

int main()
{
    cout << "5! = " << factorial(5) << endl;
    cout << "1! = " << factorial(1) << endl;
    cout << "0! = " << factorial(0) << endl;

    return 0;
}
