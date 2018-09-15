#ifndef X_Y_CLASS
#define X_Y_CLASS
class Y;
class X
{
public:
	X();
private:
	Y *y_pointer = nullptr;	
};
class Y
{
public:
	Y();
private:
	X x_object;
};
#endif