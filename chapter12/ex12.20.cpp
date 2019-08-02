/***************************************************************************
 *  @file       The code is for the exercises in C++ Primmer 5th Edition
 *  @author     Packy.A
 *  @date       22  May 2019
 *  @remark
 ***************************************************************************/

#include <memory>
#include <iostream>
#include "StrBlobPtr.h"
#include <string>
#include <vector>
#include <sstream>
using std::string;
using std::vector;
int main() {

	StrBlob myfile;
	StrBlobPtr pMyFile(myfile);
	string line;
	while (std::getline(std::cin, line))
	{
		myfile.push_back(line);
		//std::stringstream sstream(line);
		//string word;
		//while (sstream >> word) {
		//	;
		//}
	}
	for (size_t i = 0; i < myfile.size(); ++i) {
		std::cout << pMyFile.deref()<< '\n';
		pMyFile.incr();
	}
	return 0;
 }