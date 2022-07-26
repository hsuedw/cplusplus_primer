/*
 * Modified from exercise2.41-c.cpp
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
    Sales_data sum, trans;
    double price = 0;

    cout << "Please enter sales records with the same ISBN: " << endl;
    if (cin >> sum.bookNo >> sum.units_sold >> price) {
        sum.revenue = price * sum.units_sold; 
        while (cin >> trans.bookNo >> trans.units_sold >> price) {
            trans.revenue = price * trans.units_sold;

            if (sum.bookNo == trans.bookNo) {
                sum.units_sold += trans.units_sold;
                sum.revenue += trans.revenue;
            } else {
                cout << "The input ISBN is not the same." << endl;
                return -2;    
            }
        } // end of while-loop
    } else {
       cout << "No data input!" << endl;
       return -1;
    }

    cout << "ISBN, number of copies sold, and total revenue, and average price: "
         << sum.bookNo << " " << sum.units_sold << " " << sum.revenue << " " << sum.revenue / sum.units_sold << endl;

    return 0;
}
