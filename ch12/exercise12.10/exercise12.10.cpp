#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>

using std::vector;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;
using std::shared_ptr;
using std::make_shared;


void process(shared_ptr<int> ptr)
{
    // use ptr
}

int main(int argc, char *argv[])
{
    shared_ptr<int> p(new int(42)); // reference count is 1
    process(shared_ptr<int>(p)); // Create a temporary object which is a smart
                                 // pointer pointing to the memory to which p points.
                                 // Therefore, the reference count becomes 2.
                                 // After process finishes, the reference count will be 
                                 // decremented to 1.
				 // Therefore, this usage is correct.

    *p = 100;
    cout << *p << endl;

    return 0;
}
