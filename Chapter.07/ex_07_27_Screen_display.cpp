#include "ex_07_27.h"
int main(int argc, char const *argv[])
{
	Screen myScreen(5,5,'X');
	myScreen.move(4,0).set('#').display(std::cout);
	std::cout << "\n";
	myScreen.display(std::cout);
	std::cout << "\n";
	const Screen myScreen1(2,2,'6');
	myScreen1.display(std::cout);
	return 0;
}