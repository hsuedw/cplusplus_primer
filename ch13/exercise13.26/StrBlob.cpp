/*
 * This solution is modified from Exercise 12.20
 */

#include "StrBlob.h"
#include "StrBlobPtr.h"

StrBlob::StrBlob(): data(make_shared<vector<string>>()) {}

StrBlob::StrBlob(initializer_list<string> il): 
              data(make_shared<vector<string>>(il)) {}

// copy constructor (add for Exercise 13.26)
StrBlob::StrBlob(const StrBlob &rhs) : data(make_shared<vector<string>>(*rhs.data)) {}

// copy-assigument operator (add for Exercise 13.26)
StrBlob &StrBlob::operator=(const StrBlob &rhs)
{
    data = make_shared<vector<string>> (*rhs.data);
    return *this;
}

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


StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

