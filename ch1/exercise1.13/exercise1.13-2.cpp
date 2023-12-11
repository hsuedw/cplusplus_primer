#include <iostream>

int main()
{
    for (int i = 10; i >= 0; --i) {
        std::cout << i;
	if (i != 0) {
            std::cout << ", ";
	}
    }
    std::cout << std::endl;

    return 0;
}
