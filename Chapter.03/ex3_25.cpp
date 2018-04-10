///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief p93 grade program with iterator
///

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <ctime>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char const *argv[])
{
	srand(time(0));
	std::vector<unsigned> grade_vec(5), scores(11);
	for(auto &grade : grade_vec){
		grade = rand()%100;
		cout << grade << ' '; 
	}
	cout << endl;
	std::vector<unsigned>::iterator level = scores.begin();
	for (std::vector<unsigned>::const_iterator it = grade_vec.cbegin(); it != grade_vec.cend(); ++it)
	{
		if(*it < 100) ++*(level + *it / 10);
	}
	for(auto cnt : scores)
		cout << cnt << ' ';
	cout << endl;
	return 0;
}