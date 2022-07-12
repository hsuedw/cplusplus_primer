#include <iostream>
int main()
{
    // currVal is the number we're counting; we'll read new values int val
    int currVal = 0, val = 0;
    // read first number and ensure that we have data to process
    if (std::cin >> currVal) {
        int cnt = 1;  // store the count for the current value we're processing
        while (std::cin >> val) { // read the remaining numbers
            if (val == currVal) { // if the values are the same
                ++cnt;            // add 1 to cnt
            } else { // otherwise, prient the coutn for the previous value
                std::cout << currVal << " occurs "
			  << cnt << " times" << std::endl;
                currVal = val;    // remember the new value
                cnt = 1;
            }
        } // while loop ends here
        // remember to print the count for the last value in the file
        std::cout << currVal << " occurs "
                  << cnt << " times" << std::endl;
    } // outermost if statement ends here
    return 0;
}

/*
 * $ ./exercise1.18 
 * 23 23 23 23 23 
 * 23 occurs 5 times
 *
 * $ ./exercise1.18 
 * 20 21 22 23 24
 * 20 occurs 1 times
 * 21 occurs 1 times
 * 22 occurs 1 times
 * 23 occurs 1 times
 * 24 occurs 1 times
*/
