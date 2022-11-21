#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>

#include "StrBlob.h"

// This code is modified from Exercise 12.2 to verify my answer for this
// Exercise (12.5).

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
        StrBlob b2 = StrBlob({ "John", "Mary", "George" }); // copy initialize, ok
        //StrBlob b2 = { "John", "Mary", "George" }; // copy initialize, error
        b1 = b2;
	b2.push_back("Charlotte");
    }

    cout << b1.size() << endl;
    cout << "front: " << b1.front() << endl;
    cout << "back: " << b1.back() << endl;

    StrBlob b3({ "Kelly", "Kate", "Hellen", "Bob", "Lucy" }); // direct initialize
    cout << "b3 front: " << b3.front() << endl;
    cout << "b3 back: " << b3.back() << endl;

    // If the constructor taking an initializer_list is declared as explicit, 
    // the following code is ilegal.
    //StrBlob b4;
    //b4 = { "Angus", "Bruce", "Jack" };
    //cout << "b4 front: " << b3.front() << endl;
    //cout << "b4 back: " << b3.back() << endl;


    return 0;
}
