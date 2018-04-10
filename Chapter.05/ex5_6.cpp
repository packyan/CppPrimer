///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief
/// Use conditional operators to convert digital grades to alpha grades
///
#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
int main(int argc, char const *argv[])
{
	const std::vector<string> scores{"F","D", "C", "B", "A", "A++"};
	int test[] = {12,34,56,78,99,100,85,65,78};
	for(int grade : test){
		string level;
		level = grade < 60 ? scores[0] : grade == 100? scores[(grade - 50) / 10] : \
		grade % 10 > 7 ? scores[(grade - 50) / 10]+"+" : \
		 grade % 10 < 3 ? scores[(grade - 50) / 10] + "+" : scores[(grade - 50) / 10] ;
		cout << "socres: " << grade << " level : " << level << endl; 
	}

	return 0;
}