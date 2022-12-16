#ifndef __STRBLOB_H__
#define __STRBLOB_H__

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <iostream>

using std::vector;
using std::string;
using std::initializer_list;
using std::shared_ptr;
using std::make_shared;
using std::weak_ptr;
using std::runtime_error;
using std::out_of_range;

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob {
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;
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
    string &back();
    const string &front() const;
    const string &back() const;

    StrBlobPtr begin();
    StrBlobPtr end();
    ConstStrBlobPtr begin() const;
    ConstStrBlobPtr end() const;

private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;
};

StrBlob::StrBlob(): data(make_shared<vector<string>>()) {}

StrBlob::StrBlob(initializer_list<string> il): 
              data(make_shared<vector<string>>(il)) {}

void StrBlob::check(size_type i, const string &msg) const
{
    if (i >= data->size()) 
        throw out_of_range(msg);
}

string &StrBlob::front()
{
    // if the vector is empty, check will throw
    check(0, "front on empty StrBlob");
    return data->front();
}

const string &StrBlob::front() const
{
    // if the vector is empty, check will throw
    check(0, "front on empty StrBlob");
    return data->front();
}

string &StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

const string &StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back()
{
    check(0, "pob_back on empty StrBlob");
    data->pop_back();
}

class StrBlobPtr {
    friend bool eq(const StrBlobPtr &, const StrBlobPtr &);
    friend bool neq(const StrBlobPtr &, const StrBlobPtr &);
public:
    StrBlobPtr(): curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0): 
            wptr(a.data), curr(sz) {}
    string &deref() const;
    StrBlobPtr &incr(); // prefix increment
    StrBlobPtr &decr(); // prefix decrement
private:
    shared_ptr<vector<string>>
        check(size_t, const string &) const;
    weak_ptr<vector<string>> wptr;
    size_t curr;
};

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const
{
    auto ret = wptr.lock(); // If the vector in StrBlob is still around, ret is
                            // the shared_ptr points to that vector.
    if (!ret) {
        // The vector has been freed.
        throw runtime_error("Unbound StrBlobPtr");
    }
    if (i >= ret->size()) {
        // The index is out of the range.
        throw out_of_range(msg);
    }

    // The vector is still around and the index is valid.
    // Return the shared_ptr to the vector.
    return ret;
}

string &StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");   
    return (*p)[curr];  // (*p) is the vector to which this object points
}

StrBlobPtr &StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr &StrBlobPtr::decr()
{
    if (curr == 0) {
        throw out_of_range("Index will be decremented to -1");
    }
    --curr;
    return *this;
}


StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}


bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto left = lhs.wptr.lock();
    auto right = rhs.wptr.lock();

    if (left == right) {
        return !left || lhs.curr == rhs.curr;
    }
    return false;
}

bool neq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !eq(lhs, rhs);
}

// ----------- begin of ConstStrBlobPtr
class ConstStrBlobPtr {
    friend bool eq(ConstStrBlobPtr &, ConstStrBlobPtr &);
    friend bool neq(ConstStrBlobPtr &, ConstStrBlobPtr &);
public:
    ConstStrBlobPtr(): curr(0) {}
    ConstStrBlobPtr(const StrBlob &a, size_t sz = 0): 
            wptr(a.data), curr(sz) {}
    const string &deref() const;
    ConstStrBlobPtr &incr(); // prefix increment
    ConstStrBlobPtr &decr(); // prefix decrement
private:
    const shared_ptr<vector<string>>
        check(size_t, const string &) const;
    const weak_ptr<vector<string>> wptr;
    size_t curr;
};

const shared_ptr<vector<string>> ConstStrBlobPtr::check(size_t i, const string &msg) const
{
    auto ret = wptr.lock(); // If the vector in StrBlob is still around, ret is
                            // the shared_ptr points to that vector.
    if (!ret) {
        // The vector has been freed.
        throw runtime_error("Unbound StrBlobPtr");
    }
    if (i >= ret->size()) {
        // The index is out of the range.
        throw out_of_range(msg);
    }

    // The vector is still around and the index is valid.
    // Return the shared_ptr to the vector.
    return ret;
}

const string &ConstStrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");   
    return (*p)[curr];  // (*p) is the vector to which this object points
}

ConstStrBlobPtr &ConstStrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

ConstStrBlobPtr &ConstStrBlobPtr::decr()
{
    if (curr == 0) {
        throw out_of_range("Index will be decremented to -1");
    }
    --curr;
    return *this;
}

ConstStrBlobPtr StrBlob::begin() const
{
    return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::end() const
{
    auto ret = ConstStrBlobPtr(*this, data->size());
    return ret;
}

bool eq(ConstStrBlobPtr &lhs, ConstStrBlobPtr &rhs)
{
    auto left = lhs.wptr.lock();
    auto right = rhs.wptr.lock();

    if (left == right) {
        return !left || lhs.curr == rhs.curr;
    }
    return false;
}

bool neq(ConstStrBlobPtr &lhs, ConstStrBlobPtr &rhs)
{
    return !eq(lhs, rhs);
}

// ----------- end of ConstStrBlobPtr

#endif //__STRBLOB_H__
