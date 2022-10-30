#include <vector>
#include <iostream>
#include <iterator>

using std::vector;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char *argv[])
{
    vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = vec.end();
    while (iter != vec.begin()) {
        cout << *--iter;
	if (iter != vec.begin()) {
            cout << " ";
	}
    } 
    cout << endl;

    return 0;
}
