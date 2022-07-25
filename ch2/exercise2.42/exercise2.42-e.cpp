#include <iostream>
#include "Sales_data.h"

int main()
{
    Sales_data total;
    double price = 0;

    if (std::cin >> total.bookNo >> total.units_sold >> price) {
        total.revenue += price * total.units_sold;

        Sales_data trans;
        while (std::cin >> trans.bookNo >> trans.units_sold >> price) {
            trans.revenue += price * trans.units_sold;
            if (total.bookNo == trans.bookNo) {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            } else {
                std::cout << total.bookNo << " " << total.units_sold << " " << total.revenue << " " << static_cast<double>(total.revenue) / total.units_sold << std::endl;
		total.bookNo = trans.bookNo;
		total.units_sold = trans.units_sold;
		total.revenue = trans.revenue;
            }
        }
        std::cout << total.bookNo << " " << total.units_sold << " " << total.revenue << " " << static_cast<double>(total.revenue) / total.units_sold << std::endl;
    } else {
        std::cout << "No input data!" << std::endl;
        return -1; 
    }

    return 0;
}
