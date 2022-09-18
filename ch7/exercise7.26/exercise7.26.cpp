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
    Sales_data item1;
    cout << "item1: ";
    print(cout, item1) << endl;

    Sales_data item2("aabbccddee");
    cout << "item2: ";
    print(cout, item2) << endl;

    Sales_data item3("ffgghhiijj", 123, 456);
    cout << "item3: ";
    print(cout, item3) << endl;

    cout << "Please input one transaction: ";
    Sales_data item4(cin);
    cout << "item4: ";
    print(cout, item4) << endl;

    return 0;
}
