#include <iostream>
#include "Sales_data.h"

int main()
{
    Sales_data trans1, trans2;
    double price = 0;

    std::cout << "Please enter two transactions with the same ISBN: " << std::endl;
    std::cin >> trans1.bookNo >> trans1.units_sold >> price;
    trans1.revenue = trans1.units_sold * price;
    std::cin >> trans2.bookNo >> trans2.units_sold >> price;
    trans2.revenue = trans2.units_sold * price;

    if (trans1.bookNo == trans2.bookNo) {
        std::cout << "ISBN, number of copies sold, and total revenue, and average price: ";
        int total_sold = trans1.units_sold + trans2.units_sold;
        int total_revenue = trans1.revenue + trans2.revenue;
	double avg_price = static_cast<double>(total_revenue) / total_sold;
        std::cout << trans1.bookNo << " " << total_sold << " " << total_revenue << " " << avg_price << std::endl;
    } else {
        std::cout << "The ISBNs of the two input transactions are not the same." << std::endl;
    }


    return 0;
}
