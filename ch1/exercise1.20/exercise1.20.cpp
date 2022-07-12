#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item book;

    std::cout << "Please enter the sales record: " << std::endl;
    // read ISBN, number of copies sold, and sales price
    while (std::cin >> book) {
        std::cout << "ISBN, number of copies sold, and total revenue, and average price: ";
        std::cout << book << std::endl;
    }

    return 0;
}
