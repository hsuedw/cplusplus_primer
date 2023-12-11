#include <iostream>
#include <utility>

int main() {
    std::cout << "Enter two integers: " << std::endl;

    int left, right;
    std::cin >> left >> right;
    if (left > right) {
	    std::swap(left, right);
    }

    while (left <= right) {
        std::cout << left;
	if (left != right) {
            std::cout << ", ";
	}
        ++left;
    }
    std::cout << std::endl;

    return 0;
}
