#include <iostream>

#include "Sales_data.h"

int main() {
	Sales_data trans1("Learn C the hard way", 12, 33.5);

	std::cout << "----- Transaction 1 -----------" << std::endl;
	std::cout << trans1 << std::endl;

	Sales_data trans2;
	std::cin >> trans2;
	std::cout << "----- Transaction 2 -----------" << std::endl;
	std::cout << trans2;

	Sales_data trans3 = trans2 + trans1;
	std::cout << "----- Transaction 3 -----------" << std::endl;
	std::cout << trans3;

	return 0;
}
