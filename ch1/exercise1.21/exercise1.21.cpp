#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item item1, item2;

    std::cout << "Please enter two sales records with the same ISBN: " << std::endl;
    std::cin >> item1 >> item2;

    if (compareIsbn(item1, item2)) {
        std::cout << "ISBN, number of copies sold, and total revenue, and average price: ";
        Sales_item item = item1 + item2;
        std::cout << item << std::endl;
    } else {
        std::cout << "The ISBNs of the two input items are not the same." << std::endl;
    }

    return 0;
}
