#include "ex_07_32.h"
int main(int argc, char const *argv[])
{
	Screen s1(3,3,'x');
	Screen s2(4,4,'Y');
	Window_mgr Wmgr;
	Wmgr.push(&s1);
	Wmgr.push(&s2);
	Wmgr.clear(0);
	s1.display(std::cout);
	s2.display(std::cout);
	return 0;
}