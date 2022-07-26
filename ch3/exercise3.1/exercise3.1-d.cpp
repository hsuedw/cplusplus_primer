/*
 * Modified from exercise2.41-a.cpp
 */

#include <string>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

struct Sales_data {
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main()
{
    Sales_data trans;
    double price;

    cout << "Please enter the transaction: " << endl;
    while (cin >> trans.bookNo >> trans.units_sold >> price) {
        cout << "ISBN, number of copies sold, and total revenue, and average price: ";
	trans.revenue = trans.units_sold * price;
        cout << trans.bookNo << " " << trans.units_sold << " " << trans.revenue << endl;
    }

    return 0;
}
