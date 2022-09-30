#include <iostream>
#include <fstream>
#include "Sales_data.h"

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;
using std::ofstream;

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

ofstream &write_to_file(ofstream &ofs, const Sales_data &trans)
{
    ofs << "ISBN: " << trans.isbn() 
        << ", units sold: " << trans.units_sold 
        << ", revenue: " << trans.revenue
        << ", average price: " << trans.avg_price();
    return ofs;
}

int main(int argc, char *argv[])
{
    ofstream ofs(argv[1], ofstream::app);
    if (argc < 2 || !ofs.is_open()) {
        cerr << "Cannot open the output file." << endl;
        return -1;
    }

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
                // Write results for the previous book to the open file
                write_to_file(ofs, total) << endl;
                total = trans; // total now refers to the next book
            }
        }
        // Write results for the previous book to the open file
        write_to_file(ofs, total) << endl;
    } else {
        // no input! warn the user
        cerr << "No data?!" << endl;
        return -1;  // indicate failure
    }

    ofs.close();

    return 0;
}
