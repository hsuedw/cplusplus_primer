#include <iostream>

int main() {
    int n = 10;

    while (n >= 0) {
        std::cout << n;
	if (n != 0) {
            std::cout << ", ";
	}
	--n;
    }
    std::cout << std::endl;

    return 0;
}
