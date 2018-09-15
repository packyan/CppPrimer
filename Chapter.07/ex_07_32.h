
// *.h files should not contain using declaration.
#ifndef SCREEN_H
#define SCREEN_H
#include <iostream>
#include <string>
#include <vector>
class Screen;
class Window_mgr{
public:
    using ScreenIndex = std::vector<std::string>::size_type;
    void clear(ScreenIndex);
    void push(Screen*);
private:
    std::vector<Screen*> screens;
};
class Screen
{
public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(int h, int w): hight(h), width(w), contents(h * w,' '){} // ex_07_24
    Screen(int h, int w, char c) : hight(h), width(w), contents(h * w, c){}
    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r * width + c]; }

    friend class Window_mgr;
    friend void Window_mgr::clear(ScreenIndex);

    inline Screen &move(int rows, int cols);
    inline Screen &set(int rows, int cols, char ch);
    inline Screen &set(char ch);
    inline Screen &display(std::ostream &os);
    inline const Screen &display(std::ostream &os) const;
    //~Screen();
private:
    void do_dispaly(std::ostream &os) const {os << contents;}
private:
    pos cursor = 0;
    pos hight = 0, width = 0;
    std::string contents;
    
};
inline
Screen & Screen::move(int rows, int cols){
    cursor = rows*width + cols;
    return *this;
}

inline
Screen & Screen::set(int rows, int cols, char ch){
    contents[rows*width+cols] = ch;
    return *this;
}

inline
Screen & Screen::set(char ch){
    contents[cursor] = ch;
    return *this;
}


inline
Screen & Screen::display(std::ostream &os){
    do_dispaly(os);
    std::cout <<" dispaly non const" << std::endl;
    return *this;
}

inline
const Screen & Screen::display(std::ostream &os) const {
    do_dispaly(os);
    std::cout <<" dispaly const" << std::endl;
    return *this;
}

void Window_mgr::clear(ScreenIndex i){
    Screen *s = screens[i];
    (*s).contents = std::string((*s).hight * (*s).width, ' ');
}

void Window_mgr::push(Screen *s){
    screens.push_back(s);
}
#endif