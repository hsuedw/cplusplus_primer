#include <string>
#include <iostream>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main()
{
    Sales_data trans1, trans2;
    double price = 0;

    if (std::cin >> trans1.bookNo >> trans1.units_sold >> price) {
        int transCnt = 1;
        while (std::cin >> trans2.bookNo >> trans2.units_sold >> price) {
            if (trans1.bookNo == trans2.bookNo) {
                ++transCnt;
            } else {
                std::cout << trans1.bookNo << " has " << transCnt << " transactions." << std::endl;
                transCnt = 1;
		trans1.bookNo = trans2.bookNo;
		trans1.units_sold = trans2.units_sold;
		trans1.revenue = trans2.revenue;
            }
        }
	std::cout << trans1.bookNo << " has "  << transCnt << " transactions." << std::endl;
    } else {
        std::cout << "No input data!" << std::endl;
        return -1; 
    }

    return 0;
}
