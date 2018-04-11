///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief 
/// 
///
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
int main(int argc, char const *argv[])
{
	int i,j;
	cout << "please enter two numbers, and the second one can NOT be ZERO" <<endl;
	while(cin >> i >> j){
		
		try{
			if(!j) 
				throw std::runtime_error("ERROR devide zero\n"); // check firstly
			cout << " i / j = " << i/j << endl;	
			cout << "please enter two numbers, and the second one can NOT be ZERO" <<endl;
		}
		catch(std::runtime_error err){
			cout << err.what() 
				<<"\nTry again? Enter y or n" << endl;
			char c;
			cin >> c;
			if(!cin || c == 'n') break;
			cout << "please enter two numbers, and the second one can NOT be ZERO" <<endl;
		}
	}
	return 0;
}
