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
int main(int argc, char const *argv[])
{
	string curr_str, pre_str;
	while(cin >> curr_str){
		if(curr_str == pre_str){
			cout << curr_str << " has been occured two times" << endl;
			break;
		}
		else
			pre_str = curr_str;
	}
	if(cin.eof()){
		cout << "No word occured two times" <<endl;
	}
	return 0;
}