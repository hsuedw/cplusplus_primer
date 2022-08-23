#include <iostream>

/*
 * Although the comma operator compress several statement into one, I think
 * the coding style diminishes the readability of this code.
 */

int main()
{
    int sum = 0, val = 1;
    // keep executing the while as long as val is less than or equal to 10
    while (val <= 10)
        sum += val, ++val;
    std::cout << "Sum of 1 to 10 inclusive is "
              << sum << std::endl;
    return 0;
}
