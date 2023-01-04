#ifndef __QUERYRESULT_H__
#define __QUERYRESULT_H__

#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <memory>
#include <iostream>

#include "TextQuery.h"
#include "StrBlobPtr.h"

using std::vector;
using std::string;
using std::unordered_map;
using std::set;
using std::shared_ptr;
using std::ostream;

class QueryResult {
    friend ostream &print(ostream &os, const QueryResult &qr);
public:
    QueryResult(string target,
                StrBlobPtr text,
                shared_ptr<set<TextQuery::lineNumType>> lineNum) :
        target(target),
        text(text), 
	lineNum(lineNum) {}

private:
    string target;
    StrBlobPtr text;
    shared_ptr<set<TextQuery::lineNumType>>  lineNum;
};




#endif // __QUERYRESULT_H__
