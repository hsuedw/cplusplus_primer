/*
 * This solution is modified from Exercise 12.20
 */

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

    StrBlob c = b; // copy constructor
    cout << "=== Print data form c" << endl;
    StrBlobPtr ptrB = b.begin();
    while (neq(ptrB, b.end())) {
         cout << ptrB.deref() << " ";
         ptrB.incr(); 
    }
    cout << endl;


    StrBlob d;
    d = b; // copy-assignment operator
    cout << "=== Print data form d" << endl;
    StrBlobPtr ptrD = b.begin();
    while (neq(ptrD, b.end())) {
         cout << ptrD.deref() << " ";
         ptrD.incr(); 
    }
    cout << endl;

    return 0;
}
