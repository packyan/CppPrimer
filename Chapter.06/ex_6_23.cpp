///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief print array
/// 
///
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void print(const int *begin, const int *end)
{
	while(begin != end){
		cout << *begin++ << ' ';
	}
	cout << endl;
}
void print(int* const p){
	if(p) cout << *p << endl;
}
void print(const char *cp){
	if(cp)
		while(*cp)
			cout << *cp++;
		cout << endl;
}
void print(const int *p, size_t len){
	for (size_t i = 0; i < len; ++i)
	{
		cout << *(p+i) << ' ';
	}
	cout << endl;
}

int main(int argc, char const *argv[])
{
	int i = 6, j[3] = {0,1,1};
	char chararr[8] = "packyan";
	print(&i,&i+1);
	print(&i);
	print(std::begin(j), std::end(j));
	print(chararr);
	print(j,std::end(j) - std::begin(j));
	return 0;
}