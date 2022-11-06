#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include "Sales_data.h"

// I use my solution for Exercise 11.11 to verify the solution for this
// exercise (11.19).

using std::vector;
using std::multiset;
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

bool compareIsbn(const Sales_data &trans1, const Sales_data &trans2)
{
    return trans1.isbn() < trans2.isbn();
}

int main()
{
    multiset<Sales_data, decltype(compareIsbn) *> bookstore(compareIsbn);

    multiset<Sales_data, bool (*)(const Sales_data &, const Sales_data &)>::iterator it = bookstore.begin();

    return 0;
}
