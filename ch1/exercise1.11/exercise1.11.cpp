#include <iostream>

int main()
{
    std::cout <<  "Enter two numbers: " << std::endl;

    int left = 0, right = 0;
    std::cin >> left >> right;

    if (left > right) {
        int tmp = left;
	left = right;
	right = tmp;
    }

    while (left <= right) {
        std::cout << left++ << " ";
    }
    std::cout << std::endl;

    return 0;
}
