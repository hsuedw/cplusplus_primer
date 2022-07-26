/*
 * Modified from exercise2.41-b.cpp
 */

#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::cin;
using std::endl;

struct Sales_data {
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main()
{
    Sales_data trans1, trans2;
    double price = 0;

    cout << "Please enter two transactions with the same ISBN: " << endl;
    cin >> trans1.bookNo >> trans1.units_sold >> price;
    trans1.revenue = trans1.units_sold * price;
    cin >> trans2.bookNo >> trans2.units_sold >> price;
    trans2.revenue = trans2.units_sold * price;

    if (trans1.bookNo == trans2.bookNo) {
        cout << "ISBN, number of copies sold, and total revenue, and average price: ";
        int total_sold = trans1.units_sold + trans2.units_sold;
        int total_revenue = trans1.revenue + trans2.revenue;
	double avg_price = static_cast<double>(total_revenue) / total_sold;
        cout << trans1.bookNo << " " << total_sold << " " << total_revenue << " " << avg_price << endl;
    } else {
        cout << "The ISBNs of the two input transactions are not the same." << endl;
    }


    return 0;
}
