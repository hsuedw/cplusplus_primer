#ifndef __STRBLOB_H__
#define __STRBLOB_H__

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>

using std::vector;
using std::string;
using std::initializer_list;
using std::shared_ptr;
using std::make_shared;
using std::weak_ptr;
using std::runtime_error;
using std::out_of_range;

class StrBlobPtr;

class StrBlob {
    friend class StrBlobPtr;
public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    // add and remove elements
    void push_back(const string &t) { data->push_back(t); }
    void pop_back();

    // element access
    string &front();
    const string &front() const;
    string &back();
    const string &back() const;

    StrBlobPtr begin();
    StrBlobPtr end();
private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;
};

#endif //__STRBLOB_H__
