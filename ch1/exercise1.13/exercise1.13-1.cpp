#include <iostream>

int main()
{
    int sum = 0, val = 50;

    // keep executing the while as long as val is less than or equal to 100
    for (int val = 50; val <= 100; ++val) {
        sum += val;  // assigns sum + val to sum
    }
    std::cout << "Sum of 50 to 100 inclusive is "
              << sum << std::endl;

    return 0;
}
