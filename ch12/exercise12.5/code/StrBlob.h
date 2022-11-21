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
using std::out_of_range;

class StrBlob {
public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    explicit StrBlob(initializer_list<string> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    // add and remove elements
    void push_back(const string &t) { data->push_back(t); }
    void pop_back();

    // element access
    string &front();
    string &back();

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

string &StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back()
{
    check(0, "pob_back on empty StrBlob");
    data->pop_back();
}
