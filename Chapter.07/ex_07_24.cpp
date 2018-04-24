#include "ex_07_23.h"
int main(int argc, char const *argv[])
{
	Screen scr1;
	Screen scr2(2,3);
	Screen scr3(2,3,'s');
	Screen scr4 = scr3;
	std::cout << scr1.get() << ' '<< scr2.get() << ' ' << scr3.get() <<' '
	<< scr4.get()<<std::endl;
	return 0;
}