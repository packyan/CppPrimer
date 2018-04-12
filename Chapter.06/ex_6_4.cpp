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
int fact(int i);
int factRecursive(int i);
void enterFactNumber();
int main(int argc, char const *argv[])
{
	while(true){
		enterFactNumber();
	}
}
void enterFactNumber(){
	cout << "please enter a number"<<endl;
	int i;
	cin >> i;
	cout << fact(i) <<endl;
}

int fact(int i){
	if(i == 0 | i ==1) return 1;
    int ret = 1;
    ++i;
    while(i > 1){
        ret *= (--i);
    }
    return ret;
}
 
int factRecursive(int i){
	if(i == 0 | i ==1) return 1;
	else return i * factRecursive(i-1);
}