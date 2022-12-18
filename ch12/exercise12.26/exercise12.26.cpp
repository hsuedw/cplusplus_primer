#include <string>
#include <iostream>
#include <memory>

using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::allocator;

int main(int argc, char *argv[])
{
    const string::size_type n = 16;
    allocator<string> alloc;          // object that can allocate strings
    auto const p = alloc.allocate(n); // allocate n unconstructed strings
    auto q = p;                       // q will point to one past the last constructed element

    string word;
    while (q - p < n && cin >> word) {
        alloc.construct(q++, word);
    }

    auto it = p;
    while (it != q) {
        cout << *it << endl;
	++it;
    }

    while (q != p) {
        alloc.destroy(--q); // free the strings we actually allocated
    }
    alloc.deallocate(p, n);

    return 0;
}
