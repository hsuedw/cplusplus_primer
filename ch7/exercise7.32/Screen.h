#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::ostream;
using std::cout;
using std::endl;

class Screen;

class Window_mgr {
public:
    // location ID for each screen on the window
    using ScreenIndex = vector<Screen>::size_type;

    // reset the Screen at the given position to all blanks
    void clear(ScreenIndex);

    Window_mgr(); // the default constructor
private:
    vector<Screen> screens;
};

class Screen {
    friend void Window_mgr::clear(ScreenIndex);
public:
    using pos = string::size_type;

    Screen() : cursor(0), height(0), width(0) {}
    Screen(pos h, pos w, char c) : height(h), width(w), contents(h * w, c) {}
    Screen(pos h, pos w) : height(h), width(w), contents(h * w, ' ') {}

    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const;
    Screen &move(pos r, pos c);
    Screen &set(char ch);
    Screen &set(pos row, pos c, char ch);
    Screen &display(ostream &os) {
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

Window_mgr::Window_mgr() {
    screens.push_back(Screen(24, 80, ' '));
}

void Window_mgr::clear(ScreenIndex i)
{
    cout << "Window_mgr::clear(ScreenIndex i) is called." << endl;  // dbg mesg
    if (i < screens.size()) {
        // s is a reference to the Screen we want to clear
        Screen &s = screens[i];
	s.contents = string(s.height * s.width, ' ');
    }
}

inline char Screen::get(pos r, pos c) const {
    return contents[r * width + c];
}

inline Screen &Screen::move(pos r, pos c) {
    cursor = r * width + c;
    return *this;
}

Screen &Screen::set(char ch) {
    contents[cursor] = ch;
    return *this;
}

Screen &Screen::set(pos r, pos c, char ch)  {
    contents[r * width + c] = ch;
    return *this;
}
#endif // SCREEN_H
