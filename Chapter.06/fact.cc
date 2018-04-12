#include "Chapter6.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void enterANumbertoABS(){
	cout << "please enter a number"<<endl;
	int i;
	cin >> i;
	cout << myint_abs(i) <<endl;
}

unsigned myint_abs(int i){
	if(i >= 0) return static_cast<unsigned>(i) ;
	else return static_cast<unsigned>(-i);
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