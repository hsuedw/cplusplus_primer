#include <string.h>

#include "String.h"


ostream& operator<<(ostream &os, const String &s) {
    auto p = s.begin();
    while (p != s.end()) {
        os << *p++;
    }
    return os;
}

// ------------------ public member functions

String::String(): 
    elements(nullptr), first_free(nullptr), cap(nullptr) {

}

String::String(const char *const s) {
    size_t len = strlen(s);
    auto newdata = alloc_n_copy(s, s + len);

    elements = newdata.first;
    first_free = newdata.second;
}

String::String(const String &rhs) {
    auto newdata = alloc_n_copy(rhs.begin(), rhs.end());

    elements = newdata.first; 
    first_free = newdata.second;
}

String::~String() {
    free();
}

inline size_t String::size() const {
    return first_free - elements;
}

inline size_t String::capacity() const {
    return cap - elements;
}

inline char *String::begin() const {
    return elements;
}

inline char *String::end() const {
    return first_free;
}

void String::push_back(char c) {
    check_n_alloc();
    alloc.construct(first_free++, c);
}

// ------------------ private member functions

pair<char *, char *> String::alloc_n_copy(const char *b, const char *e) {
    auto data = alloc.allocate(e - b);
    return { data, uninitialized_copy(b, e, data) };
}

void String::check_n_alloc() {
    if (size() == capacity()) {
        reallocate();
    }
}

inline void String::reallocate() {
    auto newcapacity = size() ? size() * 2 : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i) {
        alloc.construct(dest++, *elem++);
    }
    free();

    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

void String::free() {
    if (elements) {
        for (auto p = first_free; p != elements; /* empty */) {
            alloc.destroy(--p);
	}
	alloc.deallocate(elements, cap - elements);
    }
}
