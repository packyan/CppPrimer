/***************************************************************************
 *  @file       The code is for the exercises in C++ Primmer 5th Edition
 *  @author     Packy.A
 *  @date       20  May 2019
 *  @remark
 ***************************************************************************/
 //! ex12.13 What happens if we excute the following code?
//!
//  generate a runtime error : double free
//!

#include <iostream>
#include <memory>

int main()
{
	{
		auto sp = std::make_shared<int>();
		auto p = sp.get();
		delete p; // delete p && sp raw memory space
	}
	// leave and sp will be destroy, so double destroy will happened
	

	return 0;
}