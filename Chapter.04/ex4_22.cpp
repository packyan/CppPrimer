///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief 
/// using Conditional operators and if-else to divide grade level.
///
#include <iostream>
#include <vector>
#include <string>
int main(int argc, char const *argv[])
{
	std::vector<int> ivec{10,20,30,40,50,60,70,80,90,100};
	std::vector<std::string> f_grade;
	std::cout << "Conditional operators" <<std::endl;
	for(int grade : ivec){
		std::cout << grade << ' ';
		std::string finalgrade = (grade > 90) ? "high-pass" : ((grade > 75) ? "pass" : ((grade > 60) ? "low-pass" : "fail"));
		f_grade.push_back(finalgrade);		
	}
	std::cout << std::endl;
	for(std::string level : f_grade)
		std::cout << level << ' ';
	std::cout << std::endl;
	f_grade.clear();
	std::cout << "if-statement" <<std::endl;
	for(int grade : ivec){
		std::cout << grade << ' ';
		std::string finalgrade;
		if(grade > 90 ) finalgrade = "high-pass";
		else if (grade > 75) finalgrade = "pass";
		else if (grade > 60) finalgrade = "low-pass";
		else finalgrade = "fail";
		f_grade.push_back(finalgrade);		
	}
	std::cout << std::endl;
	for(std::string level : f_grade)
		std::cout << level << ' ';
	std::cout << std::endl;
	return 0;
}