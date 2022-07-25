#include <iostream>
#include "Sales_data.h"

int main()
{
    Sales_data sum, trans;
    double price = 0;

    std::cout << "Please enter sales records with the same ISBN: " << std::endl;
    if (std::cin >> sum.bookNo >> sum.units_sold >> price) {
        sum.revenue = price * sum.units_sold; 
        while (std::cin >> trans.bookNo >> trans.units_sold >> price) {
            trans.revenue = price * trans.units_sold;

            if (sum.bookNo == trans.bookNo) {
                sum.units_sold += trans.units_sold;
                sum.revenue += trans.revenue;
            } else {
                std::cout << "The input ISBN is not the same." << std::endl;
                return -2;    
            }
        } // end of while-loop
    } else {
       std::cout << "No data input!" << std::endl;
       return -1;
    }

    std::cout << "ISBN, number of copies sold, and total revenue, and average price: "
              << sum.bookNo << " " << sum.units_sold << " " << sum.revenue << " " << sum.revenue / sum.units_sold << std::endl;

    return 0;
}
