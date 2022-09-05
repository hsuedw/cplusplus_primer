#include <iostream>
#include <iterator>

using std::cout;
using std::endl;
using std::begin;
using std::end;

// Because the compiler treat ia as a pointer to the first element in the 
// array argument, the size information is not passed to this function.
// print may access the elements not belonging to the array.
void print(const int ia[10])
{
    for (size_t i = 0; i != 10; ++i)
        cout << ia[i] << endl;
}

// Using a reference to an array of ten ints can limit the size of the 
// array argument to exactly ten. Because the size of an array is part
// of the type, it is safe to rely on the dimension in the body of the 
// function. However, this solution limits the usefulness of print2.
void print2(const int (&aRef)[10])
{
    for (size_t i = 0; i != 10; ++i)
        cout << aRef[i] + 10 << endl;
}

void print3(const int * const pa, size_t sz)
{
     for (size_t i = 0; i != sz; ++i)
        cout << *(pa + i) + 20 << endl;
}

void print4(const int * const pbeg, const int * const pend)
{
     for (const int *it = pbeg; it != pend; ++it)
        cout << *it + 30 << endl;
}

int main()
{
    int j[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    print(j);
    print2(j);
    print3(j, 10);
    print4(begin(j), end(j));
    return 0;
}
