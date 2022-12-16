#include "StrBlobPtr.h"

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

//----------------------------

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

