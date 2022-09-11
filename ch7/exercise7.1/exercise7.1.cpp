#include <iostream>

// NOTE: The Sales_data class is not full developed yet.
#include "Sales_data.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main()
{
    Sales_data total;  // variable to hold data for the next transaction

    // read the first transaction and ensure that there are data to process
    if (cin >> total) {
        Sales_data trans; // variable to hold the running sum

	// read and process the remaining transactions
	while (cin >> trans) {
            // if we're still processing the same book
            if (total.isbn() == trans.isbn()) {
                total += trans; // update the running total
            } else {
                // print results for the previous book
                cout << total << endl;
                total = trans; // total now refers to the next book
            }
	}
        cout << total << endl; // print the last transaction
    } else {
        // no input! warn the user
        cerr << "No data?!" << endl;
	return -1; // indicate failure
    }

    return 0;
}
