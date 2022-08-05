#include <string>
#include <iostream>

using std::string;
using std::iostream;


int txt_size()
{
    return 1024;
}

int main()
{
    //unsigned buf_size = 1024;
    //int ia[buf_size];   // (a)

    //int ia[4 * 7 - 14]; // (b)

    //int ia[txt_size()]; // (c)

    char st[11] = "fundamental"; // (d)

    return 0;
}
