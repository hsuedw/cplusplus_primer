#include <vector>
#include <iostream>
#include <algorithm>
#include "Sales_data.h"

// I use my solution for Exercise 7.21 to implement the solution for this
// exercise.

using std::vector;
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
    vector<Sales_data> sales_list;
    Sales_data trans;
    while (read(cin, trans)) {
        sales_list.push_back(trans);
    }

    sort(begin(sales_list), end(sales_list), compareIsbn);
    cout << "---------" << endl;
    for (auto &t : sales_list)
        print(cout, t) << endl;

    return 0;
}
