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
    StrBlob b1;
    {
        StrBlob b2 = { "John", "Mary", "George" };
	b1 = b2;
	b2.push_back("Charlotte");
    }

    cout << b1.size() << endl;
    cout << "front: " << b1.front() << endl;
    cout << "back: " << b1.back() << endl;

    return 0;
}
