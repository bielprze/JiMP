#include <iostream>

using namespace std;

class base {
public:
	static void fun1(){cout<<"fun1"<<endl;}		
	static void fun2(){cout<<"fun2"<<endl;}		
};

class derived:public base{
public:
	static void fun1(){cout<<"dziedziczona i przedefiniowana fun1"<<endl;}
	
};

int main(void){
	derived d1;
	
	d1.fun1();
	d1.fun2();
	
	return 0;
}
