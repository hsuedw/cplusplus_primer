#include <string>
#include <iostream>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

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
