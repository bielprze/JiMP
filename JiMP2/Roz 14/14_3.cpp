#include <iostream>

class A {
	public:
	A(){std::cout<<"konstruktor A zostal wywolany"<<std::endl;}
	~A(){std::cout<<"destruktor A zostal wywolany"<<std::endl;}	
};

class B:public A {
	public:
	B(){std::cout<<"konstruktor B zostal wywolany"<<std::endl;}
	~B(){std::cout<<"destruktor B zostal wywolany"<<std::endl;}
};

class C:public B {
	public:
	C(){std::cout<<"konstruktor C zostal wywolany"<<std::endl;}
	~C(){std::cout<<"destruktor C zostal wywolany"<<std::endl;}
};

int main(void)
{
	C obj;
	return 0;
}
