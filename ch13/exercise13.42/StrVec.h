#ifndef __STRVEC_H__
#define __STRVEC_H__

#include <utility>
#include <string>
#include <initializer_list>

class StrVec {
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(std::initializer_list<std::string> parms) :
	    elements(nullptr), first_free(nullptr), cap(nullptr) {
        for (auto x : parms) {
            push_back(x);
	}
    }
    StrVec(const StrVec&);              // copy constructor
    StrVec &operator=(const StrVec&);   // copy assignment
    ~StrVec();                          // destructor
    void push_back(const std::string&); // copy the element
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }

    std::string* operator[](size_t index) {
        return elements + index;
    }

    std::string* at(size_t index) {
        return elements + index;
    }

private:
    static std::allocator<std::string> alloc; // allocates the elements
    // Used by the functions that add elements to the StrVec
    void chk_n_alloc()
	{ if (size() == capacity()) reallocate(); }
    // utilities used by the copy constructor, assignment operator, and destructor
    std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
    void free();             // destroy the elements and free the space
    void reallocate();       // get more space and copy the existing elements
    void reallocate(size_t n);

    void reserve(size_t n);  // Allocate space for at least n elements.
    void resize(size_t n);   // Resize the container so that it has n elements.
                             // If n < c.size(), the excess elements are 
			     // discarded. If new elements must be added, they
			     // are value initialized.
    void resize(size_t n, const std::string &s);  // Resize the contaier to have n elements.
                                                  // Any elements added have value s.

    std::string *elements;   // pointer to the first element in the array
    std::string *first_free; // pointer to the first free element in the array
    std::string *cap;        // pointer to one past the end of the array
};

#endif //__STRVEC_H__
