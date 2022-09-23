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
    /*
     * The printed message will be.
     *     Sales_data(const std::string &, unsigned , double)
     *     Sales_data()
     */ 
    Sales_data d1;

    /*
     * The printed message will be
     *     Sales_data(const std::string &, unsigned , double)
     */ 
    //Sales_data d2("aabbccddee", 12, 34);

    /*
     * The printed message will be
     *     Sales_data(const std::string &, unsigned , double)
     *     Sales_data(const std::string &)
     */ 
    //Sales_data d3("aabbccddee");

    /*
     * The printed message will be
     *     Sales_data(const std::string &, unsigned , double)
     *     Sales_data()
     *     Sales_data(std::istream &)
     */ 
    //Sales_data d4(cin);

    return 0;
}
