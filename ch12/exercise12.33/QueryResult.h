
// This solution (Exercise 12.33) is modified from Exercise 12.27

#ifndef __QUERYRESULT_H__
#define __QUERYRESULT_H__

#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <memory>
#include <iostream>

#include "TextQuery.h"

using std::vector;
using std::string;
using std::unordered_map;
using std::set;
using std::shared_ptr;
using std::ostream;

class QueryResult {
    friend ostream &print(ostream &os, const QueryResult &qr);
public:
    typedef set<TextQuery::lineNumType>::const_iterator lineIt;
    QueryResult(string target,
                shared_ptr<vector<string>> text,
                shared_ptr<set<TextQuery::lineNumType>> lineNum) :
        target(target),
        text(text), 
	lineNum(lineNum) {}

        lineIt begin() const { return lineNum->begin(); }
        lineIt end() const { return lineNum->end(); }
	shared_ptr<vector<string>> get_file() { return text; }
private:
    string target;
    shared_ptr<vector<string>> text;
    shared_ptr<set<TextQuery::lineNumType>>  lineNum;
};




#endif // __QUERYRESULT_H__
