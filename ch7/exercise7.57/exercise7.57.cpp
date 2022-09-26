#include <iostream>
#include "Account.h"

using std::cout;
using std::endl;

int main()
{
    Account ac1;
    Account ac2("Edward");
    Account ac3("Angus", 123.45);

    print(cout, ac1) << endl;
    print(cout, ac2) << endl;
    print(cout, ac3) << endl;
    return 0;
}
