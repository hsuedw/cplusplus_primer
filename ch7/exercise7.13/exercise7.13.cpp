#include <iostream>
#include "Sales_data.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::istream;
using std::ostream;

istream &read(istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();
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
    Sales_data total(cin);
    if (cin) {
        Sales_data trans(cin);
        do {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
	    } else {
                print(cout, total) << endl;
                total = trans;
	    }
        } while (read(cin, trans));
        print(cout, total) << endl;
    } else {
        cerr << "No data?!" << endl;
    }

    return 0;
}
