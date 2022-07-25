#include <iostream>
#include "Sales_data.h"

int main()
{
    Sales_data trans;
    double price;

    std::cout << "Please enter the transaction: " << std::endl;
    while (std::cin >> trans.bookNo >> trans.units_sold >> price) {
        std::cout << "ISBN, number of copies sold, and total revenue, and average price: ";
	trans.revenue = trans.units_sold * price;
        std::cout << trans.bookNo << " " << trans.units_sold << " " << trans.revenue << std::endl;
    }

    return 0;
}
