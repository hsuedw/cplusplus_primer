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

    // p.get() returns the plain pointer managed by p and bind it to a
    // shared_ptr, so the process parameter, ptr, will manage the memory, which
    // is managed by p. Therefore, two independent smart pointers, p and ptr,
    // will point to the same memory and their reference count will both be 1.
    // After proccess finishes, the reference count of ptr will be decremented
    // to 0 and the memory will be freed. This makes p a dangling pointer.
    process(shared_ptr<int>(p.get()));

    // After process finishes, the behavior is undefined to access the memory 
    // that was managed by p.
    *p = 100;
    cout << *p << endl;

    return 0;
}
