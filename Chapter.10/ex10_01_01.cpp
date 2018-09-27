#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>


using std::string;
using std::list;
using std::vector;
using std::count;
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char* argv[]){

	std::vector<int> vec;
	int temp = 0;
	cout << "Please input numbers: " << endl;
	while(cin >> temp){
		vec.push_back(temp);
	}
	cin.clear();
	clearerr(stdin);
	cin.sync();
	cout << "Please input the number to find:" << endl;
	int number = 0 ;
	cin >> number;
	cout << number << " occers " << count(vec.begin(), vec.end(), number) << " times" << endl;
	
	cin.clear();
	clearerr(stdin);
	cin.sync();


	list<string> list_str;
	string buf_str;
	cout << "Please input strings: " << endl;
	while(cin >> buf_str){
		list_str.push_back(buf_str);
	}
	cin.clear();
	clearerr(stdin);
	cin.sync();
	cout << "Please input the string to find:" << endl;
	cin >> buf_str;
	cout << buf_str << " occers " << count(list_str.begin(), list_str.end(),buf_str) << " times" << endl;
	
	return 0;
}