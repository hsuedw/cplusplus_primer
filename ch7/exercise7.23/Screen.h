#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <iostream>

using std::string;

class Screen {
public:
    using pos = string::size_type;

    Screen() : cursor(0), height(0), width(0) {}
    Screen(pos h, pos w, char c) : height(h), width(w), contents(h * w, c) {}

    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const;
    Screen &move(pos r, pos c);
private:
    pos cursor = 0;
    pos height = 0;
    pos width = 0;
    string contents;
    mutable size_t access_ctr; // track how often each Screen member function is called
};

inline char Screen::get(pos r, pos c) const {
    return contents[r * width + c];
}

inline Screen &Screen::move(pos r, pos c) {
    cursor = r * width + c;
    return *this;
}

#endif // SCREEN_H
