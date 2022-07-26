/*
 * Modified from exercise2.41-d.cpp
 */

#include <string>
#include <iostream>
using std::string;
using std::cin;
using std::cout;
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

    if (cin >> trans1.bookNo >> trans1.units_sold >> price) {
        int transCnt = 1;
        while (cin >> trans2.bookNo >> trans2.units_sold >> price) {
            if (trans1.bookNo == trans2.bookNo) {
                ++transCnt;
            } else {
                cout << trans1.bookNo << " has " << transCnt << " transactions." << endl;
                transCnt = 1;
		trans1.bookNo = trans2.bookNo;
		trans1.units_sold = trans2.units_sold;
		trans1.revenue = trans2.revenue;
            }
        }
	cout << trans1.bookNo << " has "  << transCnt << " transactions." << endl;
    } else {
        cout << "No input data!" << endl;
        return -1; 
    }

    return 0;
}
