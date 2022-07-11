#include <iostream>

int main()
{
    int sum = 0;
    for (int i = -100; i <= 100; ++i) {
        sum += i;
    }

    // sum is 0.
    std::cout << sum << std::endl;

    return 0;
}
