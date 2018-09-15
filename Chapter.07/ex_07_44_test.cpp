#include <iostream>
#include <vector>

class NoDefault{
public:
	NoDefault(int ii):i(ii){}
private:
    int i;
    int j;
};

class C{
public:
    C():nodef(0) {}
private:   
    NoDefault nodef;

};

int main(int argc, char const *argv[])
{
	C c;
	std::vector<C> vec(10);
	//NoDefault def;
	std::vector<NoDefault> vdef(10);
	return 0;
}