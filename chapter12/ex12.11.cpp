/***************************************************************************
 *  @file       The code is for the exercises in C++ Primmer 5th Edition
 *  @author     Packy.A
 *  @date       20  May 2019
 *  @remark
 ***************************************************************************/
 //!
 //! Exercise 12.11:
 //! What would happen if we called process as follows?
 //  An error was generated at run time : double free or corruption.
 //  See the comments below.

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
	process(std::shared_ptr<int>(p.get()) );
	/**
 * @brief   std::shared_ptr<int>(p.get()) construct a temporary shared_ptr
 * and copy it
 *          to the parameter.However it is not a copy of p. As a result, at
 * end of this
 *          main function p will free the memory that has been freed inside
 * process ().
 *          That's why "double freed or corruption" was generated.
 */

	std::cout << p.use_count() << "\n";
	std::cout << "the int p now points to is: " << *p << "\n";
	return 0;
}