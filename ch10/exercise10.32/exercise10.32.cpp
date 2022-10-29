#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <numeric>

#include "Sales_item.h"

using std::vector;
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::istream_iterator;
using std::ostream;

ostream &operator<<(ostream &os, vector<Sales_item> c)
{
    auto it = begin(c);
    while (it != end(c)) {
        os << it->isbn() << '\t' << it->get_units_sold() << '\t' << it->get_revenue() << '\t' << it->avg_price();
	if (it + 1 != end(c)) {
            os << endl;
	}
	++it;
    }

    return os;
}

int main()
{
    Sales_item total;
    vector<Sales_item> all_trans;

    istream_iterator<Sales_item> is_iter(cin), eof;
    auto all_trans_back_ins = back_inserter(all_trans);

    // Read all the transactions from the standard input and store them in a
    // vector whose element type is Sales_type.
    copy(is_iter, eof, all_trans_back_ins);

    // Sort all the transactions by their ISBNs.
    sort(begin(all_trans), end(all_trans), [](const Sales_item &a, const Sales_item &b){ return a.isbn() < b.isbn(); });

    auto all_trans_iter = begin(all_trans);
    vector<Sales_item> result;
    while (all_trans_iter != end(all_trans)) {
        auto left_iter = all_trans_iter + 1;
	auto right_iter = find_if(left_iter, end(all_trans), [all_trans_iter](const Sales_item &a){ return !compareIsbn(*all_trans_iter, a); });

	Sales_item tmpSum = accumulate(left_iter, right_iter, *all_trans_iter);

	result.push_back(tmpSum);

	all_trans_iter = right_iter;
    }

    cout << result << endl;

    return 0;
}
