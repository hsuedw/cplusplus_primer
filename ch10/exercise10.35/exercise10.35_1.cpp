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
    for (auto iter = vec.end() - 1; iter != vec.begin() - 1; --iter) {
        cout << *iter;
	if (iter + 1 != vec.begin()) {
            cout << " ";
	}
    } 
    cout << endl;

    return 0;
}
