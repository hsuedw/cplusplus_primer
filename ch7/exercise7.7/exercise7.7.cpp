#include <iostream>
#include "Sales_data.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;
using std::istream;

istream &read(istream& is, Sales_data& trans)
{
    double price;

    is >> trans.bookNo;
    is >> trans.units_sold;
    is >> price;
    trans.revenue = trans.units_sold * price;
    return is;
}

ostream &print(ostream& os, const Sales_data& trans)
{
    os << "ISBN: " << trans.isbn() 
       << ", units sold: " << trans.units_sold 
       << ", revenue: " << trans.revenue
       << ", average price: " << trans.avg_price();
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

int main()
{
    Sales_data total;  // variable to hold data for the next transaction

    // read the first transaction and ensure that there are data to process
    if (read(cin, total)) {
        Sales_data trans; // variable to hold the running sum

	// read and process the remaining transactions
	while (read(cin, trans)) {
            // if we're still processing the same book
            if (total.isbn() == trans.isbn()) {
                total = add(total, trans); // update the running total
            } else {
                // print results for the previous book
                print(cout,total) << endl;
                total = trans; // total now refers to the next book
            }
	}
        print(cout, total) << endl; // print the last transaction
    } else {
        // no input! warn the user
        cerr << "No data?!" << endl;
	return -1;  // indicate failure
    }

    return 0;
}
