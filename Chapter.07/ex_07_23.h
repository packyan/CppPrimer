
// *.h files should not contain using declaration.
#ifndef SCREEN_H
#define SCREEN_H
#include <iostream>
#include <string>
class Screen
{
public:
	typedef std::string::size_type pos;
	Screen() = default;
	Screen(int h, int w): hight(h), width(w), contents(h * w,' '){} // ex_07_24
	Screen(int h, int w, char c) : hight(h), width(w), contents(h * w, c){}
	char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r * width + c]; }
	//~Screen();
private:
	pos cursor = 0;
	pos hight = 0, width = 0;
	std::string contents;
	
};

#endif