#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item record1, record2;

    if (std::cin >> record1) {
        int transCnt = 1;
        while (std::cin >> record2) {
           if (compareIsbn(record1, record2)) {
                ++transCnt;
            } else {
                std::cout << record1.isbn() << " has "  << transCnt << " transactions." << std::endl;
                transCnt = 1;
                record1 = record2;
            }
	}
        std::cout << record1.isbn() << " has "  << transCnt << " transactions." << std::endl;
    } else {
        std::cout << "No input data!" << std::endl;
        return -1;
    }

    return 0;
}
