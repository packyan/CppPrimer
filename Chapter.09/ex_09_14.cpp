#include <iostream>
#include <vector>
#include <string>
#include <list>
int main(int argc, char **argv){
	std::list<const char*> list_1{"hello","cpp"};
	std::vector<std::string> v;
	v.assign(list_1.cbegin(),list_1.cend());
	for(auto str : v) std::cout << str << '\t';
	std::cout << std::endl;
	return 0;
}
