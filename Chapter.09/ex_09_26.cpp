#include <iostream>
#include <vector>
#include <list>
using std::cout;
using std::endl;
using std::list;
using std::vector;
int main(int argc, char const *argv[])
{
	int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
	vector<int> vec(ia,std::end(ia));
	list<int> list(vec.begin(),vec.end());
	for(auto it = vec.begin(); it != vec.end();){
		if(*it & 0x01) it = vec.erase(it);
		else ++it;
	}
	for(auto it = list.begin(); it != list.end();){
		if(*it & 0x01) it = list.erase(it);
		else ++it;
	}
	for(auto num:vec) cout << num << '\t';
		cout <<endl;
	for(auto num:list) cout << num << '\t';
		cout <<endl;
	return 0;
}