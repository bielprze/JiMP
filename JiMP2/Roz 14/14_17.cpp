#include <iostream>

using namespace std;

class base {

};

class der1 : private base{
	
};

class der2 : protected base{
	
};

void fun(base obj){
	cout<<"fun"<<endl;
	}

int main(void)
{
	der1 d1;
	der2 d2;
	
	fun(d1);
	fun(d2);
	return 0;
}
