#include <iostream>
#include "example.h"

using std::cout;
using std::endl;

double Example::rate = 6.5;
vector<double> Example::vec(vecSize);

int main()
{
    cout << "rate: " << Example::rate << endl;
    cout << "size of vec: " << Example::vec.size() << endl;

    return 0;
}
