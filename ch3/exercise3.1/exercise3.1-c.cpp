/*
 * Modified from Exercise 1.11
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    cout <<  "Enter two numbers: " << endl;

    int left = 0, right = 0;
    cin >> left >> right;

    if (left > right) {
        int tmp = left;
	left = right;
	right = tmp;
    }

    while (left <= right) {
        cout << left++ << " ";
    }
    cout << endl;

    return 0;
}
