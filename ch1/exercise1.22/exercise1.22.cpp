#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item sum, record;

    std::cout << "Please enter sales records with the same ISBN: " << std::endl;
    if (std::cin >> sum) {
        while (std::cin >> record) {
            if (compareIsbn(sum, record)) {
                sum += record;
            } else {
                std::cout << "The input ISBN is not the same." << std::endl;
                return -2;
	    }
	}
    
    } else {
       std::cout << "No data input!" << std::endl;
       return -1; 
    }

    std::cout << "ISBN, number of copies sold, and total revenue, and average price: " 
	      << sum << std::endl;

    return 0;
}
