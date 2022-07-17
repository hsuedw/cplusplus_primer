#include <iostream>

int main()
{
    int i, &ri = i;
    i = 5;
    ri = 10;

    /*
     * This statement prints 10 and 10.
     */
    std::cout << i << " " << ri << std::endl;

    return 0;
}
