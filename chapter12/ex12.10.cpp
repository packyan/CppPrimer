/***************************************************************************
 *  @file       The code is for the exercises in C++ Primmer 5th Edition
 *  @author     Packy.A
 *  @date       20  May 2019
 *  @remark
 ***************************************************************************/
 //!
 //! Exercise 12.10:
 //! Explain whether the following call to the process function defined on page
 //! 464 is correct. If not, how would you correct the call?
 //  correct.

#include <iostream>
#include <vector>
#include <string>
#include <memory>

void process(std::shared_ptr<int> ptr)
{
	std::cout << "in function count: " << ptr.use_count() << "\n";
}

int main()
{
	std::shared_ptr<int> p(new int(42));
	std::cout << p.use_count() << "\n";
	process(std::shared_ptr<int>(p));
	/**
	  * how the reference count change.
	  */
	std::cout << p.use_count() << "\n";
	auto q = p;
	std::cout << p.use_count() << "\n";
	std::cout << "the int p now points to is: " << *p << "\n";
	return 0;
}