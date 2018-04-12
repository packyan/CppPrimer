///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief 
/// 
///
#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
unsigned myint_abs(int i);
void enterANumbertoABS();
template <typename T> T myabs(T i);
int main(int argc, char const *argv[])
{
	while(true){
		enterANumbertoABS();
	}
}
void enterANumbertoABS(){
	cout << "please enter a number"<<endl;
	int i;
	cin >> i;
	cout << myint_abs(i) <<endl;
	cout << myabs(i) <<endl;
}

unsigned myint_abs(int i){
	if(i >= 0) return static_cast<unsigned>(i) ;
	else return static_cast<unsigned>(-i);
}

template <typename T>
T myabs(T i)
{
    return i >= 0 ? i : -i;
}
