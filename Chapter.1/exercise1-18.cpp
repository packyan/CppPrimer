#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::cin;
using std::endl;
int main()
{
	int currVal = 0, val = 0;
	if(cin >> currVal){
		int cnt = 1;
		while(cin >> val){
			if(currVal == val) 
			++cnt;
			else{
				cout << currVal << " occurs " << cnt;
				cout << (string)((cnt == 1) ? " time" : " times")<< endl;
				currVal = val;
				cnt = 1;
			}
	
		}
	cout << currVal << " occurs " << cnt;
	cout << (string)((cnt == 1) ? " time" : " times")<< endl;
	}
	return 0;	
}
//an@ubuntu:~/Desktop/C++ Primer/Chapter.1$ ./a.out 
//6 6 6 6 6 6 6 6 6 
//6 occurs 9 times
//an@ubuntu:~/Desktop/C++ Primer/Chapter.1$ ./a.out 
//1 2 3 4 5 6 7 8 9
//1 occurs 1 time
//2 occurs 1 time
//3 occurs 1 time
//4 occurs 1 time
//5 occurs 1 time
//6 occurs 1 time
//7 occurs 1 time
//8 occurs 1 time
//9 occurs 1 time

