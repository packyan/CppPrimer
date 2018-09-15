#include <iostream>
#include <vector>
#include <string>
#include <list>
int main(int argc, char **argv){
	std::cout << "list init vecor" << std::endl;
	std::list<int> list_1{1,2,3,4,5};
	std::vector<double> v2(list_1.begin(), list_1.end());
	for (std::vector<double>::iterator i = v2.begin(); i != v2.end(); ++i)
	{
		std::cout << *i << std::endl;
	}
	std::list<int> list_2(v2.begin(), v2.end());
	std::cout << " vecotr init list:" << std::endl;
	for(const auto i : list_2){
		std::cout << i << std::endl;
	}

	return 0;
}
