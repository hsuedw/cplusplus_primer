#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include "Sales_data.h"

// I use my solution for Exercise 10.12 to implement the solution for this
// exercise (11.11).

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
    Sales_data trans;

    // ------ The solution for Exercise 11.11
    // Use function type to define bookstore
    multiset<Sales_data, bool (*)(const Sales_data &, const Sales_data &)>  bookstore(compareIsbn); 

    // Use using to define an alise for the function type
    //using fun_type1 = bool (*)(const Sales_data &, const Sales_data &); 
    //multiset<Sales_data, fun_type1>  bookstore(compareIsbn);   

    // Use typedef to define an alise for the function type
    //typedef bool (*fun_type2) (const Sales_data &, const Sales_data &);
    //multiset<Sales_data, fun_type2>  bookstore(compareIsbn);   

    // Use auto and trailing type
    //using fp3 = auto (*)(const Sales_data &, const Sales_data &)->bool;
    //multiset<Sales_data, fp3>  bookstore(compareIsbn);

    // Use auto and trailing type
    //typedef auto (*fp4)(const Sales_data &, const Sales_data &)->bool;
    //multiset<Sales_data, fp4> bookstore(compareIsbn);

    while (read(cin, trans)) {
        bookstore.insert(trans);
    }
    for (const auto &x : bookstore) {
        cout << x.isbn() << endl;
    }

    return 0;
}
