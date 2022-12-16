#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iterator>

#include "StrBlob.h"
#include "StrBlobPtr.h"

using std::unordered_map;
using std::unordered_set;
using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;
using std::ifstream;

int main(int argc, char *argv[])
{
    ifstream ifs("./input.txt");
    if (!ifs.is_open()) {
        cerr << "Cannot open input.txt" << endl;
	return -1;
    }

    StrBlob b;
    string word;
    while (ifs >> word) {
        b.push_back(word);
    }

    StrBlobPtr ptr = b.begin();
    while (neq(ptr, b.end())) {
        cout << ptr.deref() << " ";
        ptr.incr();
    }
    cout << endl;

    return 0;
}
