#ifndef __STRING_H__
#define __STRING_H__

#include <iostream>
#include <memory>
#include <utility>

using namespace std;

class String {
public:
    String();  // the default constructor
    String(const char *const s);
    String(const String &rhs);  // the copy constructor

    ~String(); // the destructor

    String &operator=(const String &rhs); // the copy-assignment operator

    size_t size() const;
    size_t capacity() const;

    char *begin() const;
    char *end() const;

    void push_back(char c);

    friend ostream& operator<<(ostream &os, const String &s);

private:
    std::allocator<char> alloc;
    char *elements;
    char *first_free;
    char *cap;

    pair<char *, char *> alloc_n_copy(const char *b, const char *e);
    void check_n_alloc();
    void reallocate();
    void free();
};

ostream& operator<<(ostream &os, const String &s);

#endif // __STRING_H__
