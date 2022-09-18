#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <iostream>

using std::string;
using std::ostream;

// This code is modified from Exercise 7.27.
// It is buggy to verify whether the idea in Exercise 7.28 is correct.

class Screen {
public:
    using pos = string::size_type;

    Screen() : cursor(0), height(0), width(0) {}
    Screen(pos h, pos w, char c) : height(h), width(w), contents(h * w, c) {}
    Screen(pos h, pos w) : height(h), width(w), contents(h * w, ' ') {}

    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const;
    Screen move(pos r, pos c);
    Screen set(char ch);
    Screen set(pos row, pos c, char ch);
    Screen display(ostream &os) {
        do_display(os);
        return *this;
    }
    const Screen &display(ostream &os) const {
        do_display(os);
        return *this;
    }
private:
    pos cursor = 0;
    pos height = 0;
    pos width = 0;
    string contents;
    mutable size_t access_ctr; // track how often each Screen member function is called

    void do_display(ostream &os) const {
        os << contents;
    }
};

inline char Screen::get(pos r, pos c) const {
    return contents[r * width + c];
}

inline Screen Screen::move(pos r, pos c) {
    cursor = r * width + c;
    return *this;
}

Screen Screen::set(char ch) {
    contents[cursor] = ch;
    return *this;
}

Screen Screen::set(pos r, pos c, char ch)  {
    contents[r * width + c] = ch;
    return *this;
}
#endif // SCREEN_H
