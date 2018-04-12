///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief // Using reference to rest a varibale.
/// 
///
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void rest(int & i){
	i = 0; 
}

int main(int argc, char const *argv[])
{
	
	for (int i  = 0; cout << "Please enter a number to rest\n",
		cin >> i  ; )
	{

		cout << "i = " << i << endl;
		rest(i);
		cout << "REST"<<endl;
		cout << "i = " << i << endl;
	}
	return 0;
}