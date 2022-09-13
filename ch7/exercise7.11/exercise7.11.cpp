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
    cout << "item1: isbn: " << item1.bookNo 
	 << ", units_sold: " << item1.units_sold 
	 << ", revenue: " << item1.revenue << endl;

    Sales_data item2("aabbccddee");
    cout << "item2: isbn: " << item2.bookNo 
	 << ", units_sold: " << item2.units_sold 
	 << ", revenue: " << item2.revenue << endl;

    Sales_data item3("ffgghhiijj", 123, 456);
    cout << "item3: isbn: " << item3.bookNo 
	 << ", units_sold: " << item3.units_sold 
	 << ", revenue: " << item3.revenue << endl;

    cout << "Please input one transaction: ";
    Sales_data item4(cin);
    cout << "item4: isbn: " << item4.bookNo 
	 << ", units_sold: " << item4.units_sold 
	 << ", revenue: " << item4.revenue << endl;

    return 0;
}
