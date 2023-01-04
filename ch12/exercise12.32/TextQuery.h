#ifndef __TEXTQUEY_H__
#define __TEXTQUEY_H__

#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cctype>
#include <memory>

#include "StrBlob.h"

using std::unordered_map;
using std::unordered_set;
using std::set;
using std::vector;
using std::string;
using std::ifstream;
using std::ostream;
using std::istringstream;
using std::cout;
using std::endl;
using std::make_shared;
using std::shared_ptr;
using std::make_pair;

class QueryResult;
class StrBlob;

class TextQuery {
    friend class QueryResult;
public:
    typedef StrBlob::size_type lineNumType;

    TextQuery(ifstream &ifs);

    QueryResult query(const string &word);

    void dbgPrint();
private:
    StrBlob text;

    // Key is a word in the text. Value is a set of line numbers in which the 
    // word is located.
    shared_ptr<unordered_map<string, shared_ptr<set<lineNumType>>>> wordToLineNum;

    // Get rid of unnecessary characters, such as comma, from a word.
    string filterWord(const string &tmpWord);
};

ostream &print(ostream &os, const QueryResult &qr);

#endif // __TEXTQUEY_H__
