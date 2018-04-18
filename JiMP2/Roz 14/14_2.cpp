#include <iostream>

class A {
	public:
	A(){std::cout<<"konstruktor A zostal wywolany"<<std::endl;}
	
};

class B {
	public:
	B(){std::cout<<"konstruktor B zostal wywolany"<<std::endl;}
};

class C:public A {
	public:
	B obj();
};

int main(void)
{
	C obiekt;
	
	return 0;
}
