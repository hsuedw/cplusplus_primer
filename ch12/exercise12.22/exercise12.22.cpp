#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>

#include "StrBlob.h"

using std::unordered_map;
using std::unordered_set;
using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

int main(int argc, char *argv[])
{
    const StrBlob b1 = { "John", "Mary", "George", "Charlotte" };

    ConstStrBlobPtr cptr = b1.begin();
    ConstStrBlobPtr cEntPtr = b1.end();
    while (neq(cptr, cEntPtr)) {
        cout << cptr.deref() << " ";
        cptr.incr();
    }
    cout << endl;

    return 0;
}
