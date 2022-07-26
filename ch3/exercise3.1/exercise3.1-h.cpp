/*
 * Modified from exercise2.41-e.cpp
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
    Sales_data total;
    double price = 0;

    if (cin >> total.bookNo >> total.units_sold >> price) {
        total.revenue += price * total.units_sold;

        Sales_data trans;
        while (cin >> trans.bookNo >> trans.units_sold >> price) {
            trans.revenue += price * trans.units_sold;
            if (total.bookNo == trans.bookNo) {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            } else {
                cout << total.bookNo << " " << total.units_sold << " " << total.revenue << " " << static_cast<double>(total.revenue) / total.units_sold << endl;
		total.bookNo = trans.bookNo;
		total.units_sold = trans.units_sold;
		total.revenue = trans.revenue;
            }
        }
        cout << total.bookNo << " " << total.units_sold << " " << total.revenue << " " << static_cast<double>(total.revenue) / total.units_sold << endl;
    } else {
        cout << "No input data!" << endl;
        return -1; 
    }

    return 0;
}
