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
    for (auto r_iter = vec.crbegin(); r_iter != vec.crend(); ++r_iter) {
        cout << *r_iter;
	if (r_iter + 1 != vec.crbegin()) {
            cout << " ";
	}
    } 
    cout << endl;

    return 0;
}
