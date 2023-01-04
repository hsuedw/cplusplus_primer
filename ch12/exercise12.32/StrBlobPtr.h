#ifndef __STRBLOBPTR_H__
#define __STRBLOBPTR_H__

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>

#include "StrBlob.h"

using std::vector;
using std::string;
using std::initializer_list;
using std::shared_ptr;
using std::make_shared;
using std::weak_ptr;
using std::runtime_error;
using std::out_of_range;

class StrBlobPtr {
    friend bool eq(const StrBlobPtr &, const StrBlobPtr &);
    friend bool neq(const StrBlobPtr &, const StrBlobPtr &);
public:
    StrBlobPtr(): curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0): 
            wptr(a.data), curr(sz) {}

    string &deref() const;
    string &deref(int offset) const;
    StrBlobPtr &incr(); // prefix increment
    StrBlobPtr &decr(); // prefix decrement
private:
    shared_ptr<vector<string>>
        check(size_t, const string &) const;
    weak_ptr<vector<string>> wptr;
    size_t curr;
};

#endif //__STRBLOBPTR_H__
