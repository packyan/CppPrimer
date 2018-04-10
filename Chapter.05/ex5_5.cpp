///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief
/// Use if-else convert digital grades to Alpha grades
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
		if(grade < 60) level = scores[0];
		else {
			level = scores[(grade - 50) / 10];
			if(grade != 100)
			if(grade % 10 > 7)
				level += "+";
			else if(grade % 10 < 3)
				level += "-";
		}
		cout << "socres: " << grade << " level : " << level << endl; 
	}

	return 0;
}